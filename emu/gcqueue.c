/********************************************************************
 *	File	: gcQueue.c
 *	Author	: Neng-Fa ZHOU Copyright (C) 1994-2019
 *	Purpose	: Queue class and other utilities used by the GC
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 ********************************************************************/

#include <stdlib.h>
#include "bprolog.h"
#include "gc.h"

/************* Dynamic array of pointers   *******************/
static	int			InitDynamicArraySize = 1000000;
		int			gcDynamicArraySize;
		int			gcDynamicArrayCount;
		BPLONG_PTR	gcDynamicArray = NULL;
		
		BPLONG_PTR	global_mask_ptr = NULL;
		BPLONG		global_mask_size;

/************* Queue of terms to be rescued *******************/
		BPLONG		gcQueueSize = 1024;
		GcQueueCell	*gcQueue;
		BPLONG		gcQueueFront, gcQueueRear, gcQueueCount;

void gcQueueConstruct(void) {
	gcQueue = (GcQueueCell *)malloc(gcQueueSize * sizeof(GcQueueCell));
	if (gcQueue == NULL) myquit(OUT_OF_MEMORY, "gc");
}

void gcQueueExpand(void) {
	BPLONG		i_old = gcQueueFront;
	BPLONG		i = 0;
	GcQueueCell	*q;
	BPLONG		newGcQueueSize;

#if 0
	printf("expand  %d\n", gcQueueSize * 2);
#endif
	newGcQueueSize = 2 * gcQueueSize;
	q = (GcQueueCell *)malloc(newGcQueueSize * sizeof(GcQueueCell));
	if (q == NULL) {
		newGcQueueSize = gcQueueSize + 100000L;
		q = (GcQueueCell *)malloc(newGcQueueSize * sizeof(GcQueueCell));
		if (q == NULL) {
			fprintf(stderr, "queue size = %d\n", (int)gcQueueSize);
			myquit(OUT_OF_MEMORY, "gc");
		}
	}
	while (i < gcQueueCount) {	/* copy the elements */
		q[i].addr = gcQueue[i_old].addr;
		q[i].term = gcQueue[i_old].term;
		i++;
		i_old = (i_old + 1) % gcQueueSize;
	}
	free(gcQueue);
	gcQueue = q;
	gcQueueFront = 0;
	gcQueueRear = gcQueueFront + gcQueueSize - 1;
	gcQueueSize = newGcQueueSize;
}

#if 0
void gcQueueAdd(BPLONG_PTR addr, BPLONG term)
{
	if (gcQueueCount == gcQueueSize) {
		gcQueueExpand();
		gcQueueAdd(addr, term);
	} else {
		gcQueueRear = (gcQueueRear + 1) %  gcQueueSize;
		gcQueue[gcQueueRear].addr = addr;
		gcQueue[gcQueueRear].term = term;
		gcQueueCount++;
	}
}
#endif

BPLONG_PTR gcQueueCopy(void) {
	BPLONG_PTR	ptr;
	int			i;

	if (gcQueueCount == 0) return NULL;
	ptr = (BPLONG_PTR)malloc(gcQueueCount * sizeof(BPLONG));
	if (ptr == NULL) myquit(OUT_OF_MEMORY, "gc");
	for (i = 0; i < gcQueueCount; i++) {
		FOLLOW(ptr + i) = (BPLONG)gcQueue[i].addr;
	}
	return ptr;
}

/***********************************************/
/* dynamic array primitives */
void gcInitDynamicArray(void) {
	if (gcDynamicArray == NULL) {
		gcDynamicArraySize = InitDynamicArraySize;
		gcDynamicArray = (BPLONG_PTR)malloc(gcDynamicArraySize * sizeof(BPLONG));
		if (gcDynamicArray == NULL) myquit(OUT_OF_MEMORY, "gc");
	}
	gcDynamicArrayCount = 0;
}

#if 0
void gcAddDynamicArray(BPLONG elm)
{
	if (gcDynamicArrayCount >= gcDynamicArraySize) {
		gcExpandDynamicArray();
	}
	FOLLOW(gcDynamicArray + gcDynamicArrayCount) = elm;
	gcDynamicArrayCount++;
}
#endif

void gcExpandDynamicArray(void) {
	BPLONG_PTR	oldGcDynamicArray = gcDynamicArray;
	int			i;

	gcDynamicArray = (BPLONG_PTR)malloc(gcDynamicArraySize * 2*sizeof(BPLONG));
	if (gcDynamicArray == NULL) myquit(OUT_OF_MEMORY, "gc");
	for (i = 0; i < gcDynamicArraySize; i++) {
		FOLLOW(gcDynamicArray + i) = FOLLOW(oldGcDynamicArray + i);
	}
	gcDynamicArraySize = gcDynamicArraySize * 2;
	free(oldGcDynamicArray);
}

void gcDisposeDynamicArray(void) {
	if (gcDynamicArray != NULL) {
		free(gcDynamicArray);
		gcDynamicArray = NULL;
	}
}

/*********** utilities on bit mask ****************/
int allocateMaskArea(BPLONG size)
{
	int	i;

start:
	if (global_mask_ptr == NULL) {
		global_mask_ptr = (BPLONG_PTR)malloc(size * sizeof(BPLONG));
		if (global_mask_ptr == NULL) return BP_ERROR;
		global_mask_size = size;
	} else if (size > global_mask_size) {
		free(global_mask_ptr);
		global_mask_ptr = NULL;
		goto start;
	}

	for (i = 0; i < size; i++) {
		FOLLOW(global_mask_ptr + i) = 0;
	}
	return BP_TRUE;
}

/*****************************************************
set the corresponding mask bits of the cells at
addr, addr+1,..., addr+size-1 to be 1
	-------------------
	|     |       |   |
	-------------------
*****************************************************/

void gcSetMask(BPLONG_PTR addr, BPLONG size, BPLONG_PTR base)
{
	int	i;

	for (i = 0; i< size; i++) {
		GCSetMaskBit(addr + i, base);
	}
}

int gcIsMarked(BPLONG_PTR addr, BPLONG_PTR base)
{
	BPULONG		offset = ((BPULONG)addr - (BPULONG)base) / sizeof(BPLONG);
	BPLONG_PTR	word_ptr = global_mask_ptr + offset / NBITS_IN_LONG;
	BPULONG		word = FOLLOW(word_ptr);
	BPLONG		bitPosition = offset % NBITS_IN_LONG;
	BPULONG		mask = ((BPULONG)0x1 << bitPosition);

	if ((mask & word) == mask) return 1; else return 0;
}
