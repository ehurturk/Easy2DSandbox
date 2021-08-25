#ifndef SCRIPT3_H
#define SCRIPT3_H

#include <Easy2D/easy2d.h>

extern EZScript *script3;

static void start(struct EZSprite *parent);
static void update(struct EZSprite *parent);
static void destroy(struct EZSprite *parent);

void initscript3();

#endif