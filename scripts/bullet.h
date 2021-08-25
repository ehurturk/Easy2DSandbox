/*
	This file is a simple script header template that ca nbe used inside Easy2D applications.
	Please pay attention to comments, since they are important.
*/

#ifndef BULLET_H
#define BULLET_H

#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"

extern EZScript *newscript;

static void start(struct EZSprite *parent);
static void update(struct EZSprite *parent);
static void destroy(struct EZSprite *parent);

void initnewscript();

#endif