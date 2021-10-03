#include <stdio.h>

#include <Easy2D/easy2d.h>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/script.h"
#include "Easy2D/sprite.h"
#include "Easy2D/window.h"

#include <iostream>
#include <string>

#include "script1.h"
#include "bullet.h"

static float speed = 0.5f;
static struct EZSprite *sprite;
static int bull_counter = 0;

static struct EZSprite *createBullet() {
    struct EZSprite *spr = ezSquareSprite("newsprite", 250, 250, 0, 40, 40);
    bull_counter++;
    EZShader *shader = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                              (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(spr, shader);

    EZTexture *tex = ezLoadTexture("../res/blt.png");
    ezSetSpriteTexture(spr, tex);

    ezSpriteAddScript(spr, newscript); /* but don't add to the scene since its a prefab - will be instantiated later. */
    return spr;
}

/* bound function for handling single click input */
static void inputfun(int key, int action) {
    if (ezIsKeyDown(GLFW_KEY_LEFT_SHIFT)) {
        speed = 1.0f;
    } else {
        speed = 0.5f;
    }

    /* solve single clicks */
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        /* instantiate bullet */
        struct EZSprite *b = createBullet();
        ezInstantiateSprite((const void *)b, ezGetSpriteTransform(sprite)->position[0], ezGetSpriteTransform(sprite)->position[1], ezGetSpriteTransform(sprite)->rotation[2]);
        ezSetSpriteCollisionAsTrigger(b); /* MULTIPLE OLUNCA ABORT VERIYOR */
    }
}

/* Input function for continous inputs (I just couldn't solve single click problem, looks awkward I know */
static void pollInput(struct EZSprite *parent) {
    if (ezIsKeyDown(EZ_KEY_A)) {
        ezRotateSprite(sprite, -4);
    }

    if (ezIsKeyDown(EZ_KEY_F))
        ezDestroySprite(sprite);

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
}

static void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
    sprite = parent;
}

static void update(struct EZSprite *parent) {
    pollInput(parent);
}

static void destroy(struct EZSprite *parent) {
    free(script1);
}

EZ_INIT_SCRIPT(script1, start, update, destroy, inputfun);