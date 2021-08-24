#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/sprite.h"
#include "Easy2D/window.h"

static float speed = 0.5f;

static void pollInput(struct EZSprite *sprite) {
    if (ezIsKeyDown(EZ_KEY_A)) {
        ezRotateSprite(sprite, -4);
    }

    if (ezIsKeyDown(EZ_KEY_D)) {
        ezRotateSprite(sprite, 4);
    }

    if (ezIsKeyDown(EZ_KEY_W)) {
        EZ_VEC3(t, 0.0f, -5.0f * speed, 0.0f);
        ezTranslateSprite(sprite, t, EZ_LOCAL_REF);
    }

    if (ezIsKeyDown(EZ_KEY_S)) {
        EZ_VEC3(t, 0.0f, 5.0f * speed, 0.0f);
        ezTranslateSprite(sprite, t, EZ_LOCAL_REF);
    }

    if (ezIsKeyDown(GLFW_KEY_LEFT_SHIFT)) {
        speed = 1.0f;
    } else {
        speed = 0.5f;
    }
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
}

static void update(struct EZSprite *parent) {
    pollInput(parent);
    EZSprite *bullet = (EZSprite *)ezFindSpriteWithName("bullet");
}

EZ_INIT_SCRIPT(script1);