#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/sprite.h"

#include "script2.h"

static float speed = 0.5f;

static void pollInput(struct EZSprite *sprite) {
    if (ezIsKeyDown(GLFW_KEY_LEFT)) {
        ezRotateSprite(sprite, -6);
    }

    if (ezIsKeyDown(GLFW_KEY_RIGHT)) {
        ezRotateSprite(sprite, 6);
    }

    if (ezIsKeyDown(GLFW_KEY_UP)) {
        EZ_VEC3(t, 0.0f, -5.0f * speed, 0.0f);
        ezTranslateSprite(sprite, t, EZ_LOCAL_REF);
    }

    if (ezIsKeyDown(GLFW_KEY_DOWN)) {
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

static void destroy(struct EZSprite *parent) {
    free(script2);
}

EZ_INIT_SCRIPT(script2);