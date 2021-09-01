#include <stdio.h>

#include <Easy2D/easy2d.h>

#include "script2.h"
#include <iostream>

static float speed = 0.5f;
static struct EZSprite *sprite;

static void pollInput(int key, int action) {
    if (sprite == NULL)
        std::cout << "fuck" << std::endl;
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

    if (key == EZ_KEY_R && action == GLFW_REPEAT)
        std::cout << "WORKING" << std::endl;
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
    sprite = parent;
}

static void update(struct EZSprite *parent) {
    // pollInput(parent);
    EZSprite *bullet = (EZSprite *)ezFindSpriteWithName("bullet");
}

static void destroy(struct EZSprite *parent) {
    free(script2);
}

EZ_INIT_SCRIPT(script2, start, update, destroy, pollInput);