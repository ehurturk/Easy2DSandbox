#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/sprite.h"
#include "Easy2D/window.h"

#include "script1.h"

static float speed = 0.5f;
struct EZSprite *b;
int counter = 0;

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

    /* solve single clicks */
    if (ezIsKeyDown(GLFW_KEY_SPACE)) {
        /* instantiate bullet */
        /*
            Once instantiated, the start and update loop will be called. 
        */
        if (b != NULL) {
            printf("instantiate counter: %i\n", counter);
            counter++;
            ezInstantiateSprite((const void *)b, 100, 100);
        }
    }
}

void assign_bullet_prefab(struct EZSprite *bullet) {
    b = bullet;
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
}

static void update(struct EZSprite *parent) {
    pollInput(parent);
    EZSprite *bullet = (EZSprite *)ezFindSpriteWithName("bullet");
}

static void destroy(struct EZSprite *parent) {
    free(script1);
}

EZ_INIT_SCRIPT(script1);