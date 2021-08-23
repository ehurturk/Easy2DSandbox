#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/sprite.h"

void pollInput(struct EZSprite *sprite) {
    if (ezIsKeyDown(EZ_KEY_L)) {
        ezRotateSprite(sprite, -10);
    }

    if (ezIsKeyDown(EZ_KEY_H)) {
        ezRotateSprite(sprite, 10);
    }

    const float speed = 0.5f;

    if (ezIsKeyDown(EZ_KEY_W)) {
        EZ_VEC3(t, 0.0f, -5.0f * speed, 0.0f);
        ezTranslateSprite(sprite, t, EZ_WORLD_REF);
    }

    if (ezIsKeyDown(EZ_KEY_A)) {
        EZ_VEC3(t, -5.0f * speed, 0.0f, 0.0f);
        ezTranslateSprite(sprite, t, EZ_WORLD_REF);
    }

    if (ezIsKeyDown(EZ_KEY_S)) {
        EZ_VEC3(t, 0.0f, 5.0f * speed, 0.0f);
        ezTranslateSprite(sprite, t, EZ_WORLD_REF);
    }

    if (ezIsKeyDown(EZ_KEY_D)) {
        EZ_VEC3(t, 5.0f * speed, 0.0f, 0.0f);
        ezTranslateSprite(sprite, t, EZ_WORLD_REF);
    }
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
}

void onCollision() {
}

static void update(struct EZSprite *parent) {
    pollInput(parent);
    EZSprite *bullet = (EZSprite *)ezFindSpriteWithName("bullet");
}

EZ_INIT_SCRIPT(script1);