#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"

void pollinput() {
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
}

static void update(struct EZSprite *parent) {
    printf("GAMEOBJECT update??\n");
}

EZ_INIT_SCRIPT(gameobject);