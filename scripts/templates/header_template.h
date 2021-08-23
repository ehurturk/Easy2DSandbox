/*
	This file is a simple script header template that ca nbe used inside Easy2D applications.
	Please pay attention to comments, since they are important.
*/

#ifndef HEADER_TEMPLATE_H
#define HEADER_TEMPLATE_H

#include <Easy2D/easy2d.h>

extern EZScript *test_script;

/* NOTE: These functions (in fact, I recommend all functions inside the script) must be static in order to link object files correctly */
static void start(struct EZSprite *parent);
static void update(struct EZSprite *parent);

/* NOTE: This function name must be: init[THE EXTERN STRUCT NAME]. Since the extern struct name is test_script in here, the function name will be: inittest_script */
void inittest_script();

#endif