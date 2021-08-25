#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Easy2D/easy2d.h>

extern EZScript *gameobject;

static void start(struct EZSprite *parent);
static void update(struct EZSprite *parent);
static void destroy(struct EZSprite *parent);

void initgameobject();

#endif