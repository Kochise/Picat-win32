/********************************************************************
 *	File	: toamprofile.c
 *	Author	: Neng-Fa ZHOU Copyright (C) 1994-2019
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 ********************************************************************/

#if 0
#define ToamProfile
#endif
#ifdef ToamProfile

#include  <stdio.h>
#include "inst.h"
#include "bprolog.h"

BPLONG		total_insts, prev_inst =0;

BPLONG		execution_profile[MAXINST], seq_profile[MAXINST][MAXINST];

BPLONG		trace_inst[1000];
BPLONG		trace_rear = 0;

BPLONG_PTR	i_local_top, i_heap_top, i_trail_top, i_choice_top;
BPLONG_PTR	c_local_top, c_heap_top, c_trail_top, c_choice_top;
BPLONG_PTR	m_local_top, m_heap_top, m_trail_top, m_choice_top;

void bookkeep_inst(BPLONG inst)
{
	trace_inst[trace_rear] = inst;
	trace_rear++;
	trace_rear = (trace_rear % 1000);
}

void bookkeep_inst_init(void) {
	trace_rear = 0;
}

extern	char	*inst_name[];

void bookkeep_inst_print(void) {
	int	i;
	printf("trace_rear=%d\n", trace_rear);
	for (i = 0; i < trace_rear; i++) {
		printf(" %s	\n", inst_name[trace_inst[i]]);
	}
}

update_space_counters(BPLONG_PTR l, BPLONG_PTR h, BPLONG_PTR t)
{
	c_local_top = l;
	c_heap_top = h;
	c_trail_top = t;
	if (l < m_local_top)	m_local_top = l;
	if (h > m_heap_top)		m_heap_top = h;
	if (t < m_trail_top)	m_trail_top = t;
}

void initialize_execution_profile(void) {
	BPLONG	i;

	for (i = 0; i < MAXINST; i++) {
		execution_profile[i] = 0;
	}
}

void initialize_seq_profile(void) {
	BPLONG	i, j;

	for (i = 0; i < MAXINST; i++)
		for (j = 0; j < MAXINST; j++)
			seq_profile[i][j] = 0;
}

int start_click(void) {
	initialize_execution_profile();
	initialize_seq_profile();

	total_insts = 0;
	m_local_top = i_local_top = c_local_top;
	m_heap_top = i_heap_top = c_heap_top;
	m_trail_top = i_trail_top = c_trail_top;
	i_choice_top = 0;
#if 0
	no_postponed_vars = 0;
#endif
	return 1;
}

int access_counters(void) {
	BPLONG	insts, local_space, heap_space, trail_space, choice_space, table_space;

	insts = ARG(1, 8);

	local_space = ARG(4, 8);
	heap_space = ARG(5, 8);
	trail_space = ARG(6, 8);
	choice_space = ARG(7, 8);
	table_space = ARG(8, 8);

	unify(insts, MAKEINT(total_insts));
	unify(local_space, MAKEINT(abs((m_local_top - i_local_top))));
	unify(heap_space, MAKEINT(abs((m_heap_top - i_heap_top))));
	unify(trail_space, MAKEINT(abs((m_trail_top - i_trail_top))));
	unify(choice_space, MAKEINT(0));
	return 1;
}

int print_counters(void) {
			BPLONG	i, j;
			FILE	*fp;
	extern	char	*inst_name[];

	fp = fopen("prof", "w");
	printf("total number of instructions executed: %d\n\n", total_insts);
	fprintf(fp, "Execution profile:\n");
	for (i = 0; i < MAXINST; i++)
		fprintf(fp, "%10d %s\n", execution_profile[i], inst_name[i]);

	fclose(fp);
	fp = fopen("profseq", "w");
	for (i = 0; i < MAXINST; i++)
		for (j = 0; j < MAXINST; j++)
			if (seq_profile[i][j] != 0) fprintf(fp, "%10d (%s %s)\n", seq_profile[i][j], inst_name[i], inst_name[j]);

	fclose(fp);
	printf("local_space=%d bytes\n", (i_local_top - m_local_top) * sizeof(BPLONG));
	printf("heap_space =%d bytes\n", (m_heap_top - i_heap_top) * sizeof(BPLONG));
	printf("trail_space=%d bytes\n", (i_trail_top - m_trail_top) * sizeof(BPLONG));
	return 1;
}

void execute_inst(BPLONG opcode)
{
	total_insts++;
	update_space_counters(local_top, heap_top, trail_top);
	execution_profile[opcode]++;
	seq_profile[prev_inst][opcode]++;
	prev_inst = opcode;
}

void show_point(char *s, long n)
{
	printf("%12s %i\n", s, n);
	return;
}

void Cboot_profile(void) {
	insert_cpred("start_click", 0, start_click);
	insert_cpred("access_counters", 8, access_counters);
	insert_cpred("print_counters", 0, print_counters);
}

#endif
