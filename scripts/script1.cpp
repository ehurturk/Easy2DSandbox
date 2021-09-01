#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/sprite.h"
#include "Easy2D/window.h"

#include <iostream>

#include "script1.h"

static float speed = 0.5f;
struct EZSprite *b;
static struct EZSprite *sprite;

static void pollInput(int key, int action) {
    if (ezIsKeyDown(EZ_KEY_A)) {
        ezRotateSprite(sprite, -4);
    }

    if (ezIsKeyDown(EZ_KEY_F))
        ezDestroySprite(sprite);

    if (ezIsKeyDown(EZ_KEY_D)) {
        ezRotateSprite(sprite, 4);
    }

    if (key == EZ_KEY_W && action == GLFW_REPEAT) {
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

    /* solve single clicks */
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        /* instantiate bullet */
        if (b != NULL) {
            ezInstantiateSprite((const void *)b, ezGetSpriteTransform(sprite)->position[0], ezGetSpriteTransform(sprite)->position[1], ezGetSpriteTransform(sprite)->rotation[2]);
            ezSetSpriteCollisionAsTrigger(b); /* MULTIPLE OLUNCA ABORT VERIYOR */
        }
    }
}

void assign_bullet_prefab(struct EZSprite *bullet) {
    b = bullet;
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
    sprite = parent;
}

static void update(struct EZSprite *parent) {
    // pollInput(parent);
}

static void destroy(struct EZSprite *parent) {
    free(script1);
}

EZ_INIT_SCRIPT(script1, start, update, destroy, pollInput);