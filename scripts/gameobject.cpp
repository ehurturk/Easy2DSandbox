#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"

#include "gameobject.h"

static void pollinput(int key, int action) {
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
}

static void update(struct EZSprite *parent) {
    // printf("GAMEOBJECT update??\n");
}

static void destroy(struct EZSprite *parent) {
    free(gameobject);
}
