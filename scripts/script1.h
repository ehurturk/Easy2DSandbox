#ifndef SCRIPT1_H
#define SCRIPT1_H

#include <Easy2D/easy2d.h>

extern EZScript *script1;

static void start(struct EZSprite *parent);
static void update(struct EZSprite *parent);
static void destroy(struct EZSprite *parent);

void assign_bullet_prefab(struct EZSprite *bullet);

void initscript1();

#endif