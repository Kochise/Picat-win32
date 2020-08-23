/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class bprolog_cg_CgEvent */

#ifndef _Included_bprolog_cg_CgEvent
#define _Included_bprolog_cg_CgEvent

#ifdef __cplusplus
extern "C" {
#endif

#undef bprolog_cg_CgEvent_ActionPerformed
#define bprolog_cg_CgEvent_ActionPerformed			10L

#undef bprolog_cg_CgEvent_MouseClicked
#define bprolog_cg_CgEvent_MouseClicked				11L

#undef bprolog_cg_CgEvent_MousePressed
#define bprolog_cg_CgEvent_MousePressed				12L

#undef bprolog_cg_CgEvent_MouseReleased
#define bprolog_cg_CgEvent_MouseReleased			13L

#undef bprolog_cg_CgEvent_MouseEntered
#define bprolog_cg_CgEvent_MouseEntered				14L

#undef bprolog_cg_CgEvent_MouseExited
#define bprolog_cg_CgEvent_MouseExited				15L

#undef bprolog_cg_CgEvent_MouseMoved
#define bprolog_cg_CgEvent_MouseMoved				16L

#undef bprolog_cg_CgEvent_MouseDragged
#define bprolog_cg_CgEvent_MouseDragged				17L

#undef bprolog_cg_CgEvent_WindowClosing
#define bprolog_cg_CgEvent_WindowClosing			18L

#undef bprolog_cg_CgEvent_WindowOpened
#define bprolog_cg_CgEvent_WindowOpened				19L

#undef bprolog_cg_CgEvent_WindowIconified
#define bprolog_cg_CgEvent_WindowIconified			20L

#undef bprolog_cg_CgEvent_WindowDeiconified
#define bprolog_cg_CgEvent_WindowDeiconified		21L

#undef bprolog_cg_CgEvent_WindowClosed
#define bprolog_cg_CgEvent_WindowClosed				22L

#undef bprolog_cg_CgEvent_WindowActivated
#define bprolog_cg_CgEvent_WindowActivated			23L

#undef bprolog_cg_CgEvent_WindowDeactivated
#define bprolog_cg_CgEvent_WindowDeactivated		24L

#undef bprolog_cg_CgEvent_FocusGained
#define bprolog_cg_CgEvent_FocusGained				25L

#undef bprolog_cg_CgEvent_FocusLost
#define bprolog_cg_CgEvent_FocusLost				26L

#undef bprolog_cg_CgEvent_KeyPressed
#define bprolog_cg_CgEvent_KeyPressed				27L

#undef bprolog_cg_CgEvent_KeyReleased
#define bprolog_cg_CgEvent_KeyReleased				28L

#undef bprolog_cg_CgEvent_KeyTyped
#define bprolog_cg_CgEvent_KeyTyped					29L

#undef bprolog_cg_CgEvent_ComponentMoved
#define bprolog_cg_CgEvent_ComponentMoved			30L

#undef bprolog_cg_CgEvent_ComponentResized
#define bprolog_cg_CgEvent_ComponentResized			31L

#undef bprolog_cg_CgEvent_ComponentHidden
#define bprolog_cg_CgEvent_ComponentHidden			32L

#undef bprolog_cg_CgEvent_ComponentShown
#define bprolog_cg_CgEvent_ComponentShown			33L

#undef bprolog_cg_CgEvent_ItemStateChanged
#define bprolog_cg_CgEvent_ItemStateChanged			34L

#undef bprolog_cg_CgEvent_TextValueChanged
#define bprolog_cg_CgEvent_TextValueChanged			35L

#undef bprolog_cg_CgEvent_AdjustmentValueChanged
#define bprolog_cg_CgEvent_AdjustmentValueChanged	36L

#undef bprolog_cg_CgEvent_CgActionListener
#define bprolog_cg_CgEvent_CgActionListener			0L

#undef bprolog_cg_CgEvent_CgMouseListener
#define bprolog_cg_CgEvent_CgMouseListener			1L

#undef bprolog_cg_CgEvent_CgMouseMotionListener
#define bprolog_cg_CgEvent_CgMouseMotionListener	2L

#undef bprolog_cg_CgEvent_CgWindowListener
#define bprolog_cg_CgEvent_CgWindowListener			3L

#undef bprolog_cg_CgEvent_CgFocusListener
#define bprolog_cg_CgEvent_CgFocusListener			4L

#undef bprolog_cg_CgEvent_CgKeyListener
#define bprolog_cg_CgEvent_CgKeyListener			5L

#undef bprolog_cg_CgEvent_CgComponentListener
#define bprolog_cg_CgEvent_CgComponentListener		6L

#undef bprolog_cg_CgEvent_CgItemListener
#define bprolog_cg_CgEvent_CgItemListener			7L

#undef bprolog_cg_CgEvent_CgTextListener
#define bprolog_cg_CgEvent_CgTextListener			8L

#undef bprolog_cg_CgEvent_CgAdjustmentListener
#define bprolog_cg_CgEvent_CgAdjustmentListener		9L

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_mouse_event_to_bprolog
 * Signature: (IIIIII)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1mouse_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint, jint, jint, jint, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_window_event_to_bprolog
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1window_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_focus_event_to_bprolog
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1focus_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_key_event_to_bprolog
 * Signature: (IIICI)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1key_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint, jint, jchar, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_component_event_to_bprolog
 * Signature: (IIIIII)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1component_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint, jint, jint, jint, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_action_event_to_bprolog
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1action_1event_1to_1bprolog
	(JNIEnv *, jclass, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_text_event_to_bprolog
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1text_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jstring);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_item_event_to_bprolog
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1item_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint, jint);

/*
 * Class:     bprolog_cg_CgEvent
 * Method:    post_adjustment_event_to_bprolog
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_bprolog_cg_CgEvent_post_1adjustment_1event_1to_1bprolog
	(JNIEnv *, jclass, jint, jint, jint);

#ifdef __cplusplus
}
#endif

#endif
