#include <iostream>

#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"

#include "script3.h"

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
    ezSetSpriteCollisionAsTrigger(parent);
}

static void update(struct EZSprite *parent) {
}

static void destroy(struct EZSprite *parent) {
    free(script3);
}

EZ_INIT_SCRIPT(script3);