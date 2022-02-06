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

#ifdef __cplusplus
extern "C" {
#endif

// #include "script1.h"
// #include "bullet.h"

struct ball {
    float speed;
    int bull_counter;
    struct EZSprite *sprite;
};

// static struct EZSprite *createBullet() {
//     struct EZSprite *spr = ezSquareSprite("newsprite", 250, 250, 0, 40, 40);
//     m_instance->bull_counter++;
//     EZShader *shader = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
//                                               (EZShaderInfo){.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"});
//     ezSetSpriteShader(spr, shader);

//     EZTexture *tex = ezLoadTexture("../res/blt.png");
//     ezSetSpriteTexture(spr, tex);

//     // ezSpriteAddScript(spr, newscript); /* but don't add to the scene since its a prefab - will be instantiated later. */
//     return spr;
// }

/* Input function for continous inputs (I just couldn't solve single click problem, looks awkward I know */
static void pollInput(struct ball *ball) {
    if (ezIsKeyDown(EZ_KEY_A)) {
        ezRotateSprite(ball->sprite, -4);
    }

    if (ezIsKeyDown(EZ_KEY_F))
        ezDestroySprite(ball->sprite);

    if (ezIsKeyDown(EZ_KEY_D)) {
        ezRotateSprite(ball->sprite, 4);
    }

    if (ezIsKeyDown(EZ_KEY_W)) {
        EZ_VEC3(t, 0.0f, -5.0f * ball->speed, 0.0f);
        ezTranslateSprite(ball->sprite, t, EZ_LOCAL_REF);
    }

    if (ezIsKeyDown(EZ_KEY_S)) {
        EZ_VEC3(t, 0.0f, 5.0f * ball->speed, 0.0f);
        ezTranslateSprite(ball->sprite, t, EZ_LOCAL_REF);
    }

    if (ezIsKeyDown(GLFW_KEY_LEFT_SHIFT)) {
        ball->speed = 1.0f;
    } else {
        ball->speed = 0.5f;
    }

    /* solve single clicks */
    // if (ezIsKeyDown(GLFW_KEY_SPACE)) {
    //     /* instantiate bullet */
    //     struct EZSprite *b = createBullet();
    //     ezInstantiateSprite((const void *)b, ezGetSpriteTransform(m_instance->sprite)->position[0], ezGetSpriteTransform(m_instance->sprite)->position[1], ezGetSpriteTransform(m_instance->sprite)->rotation[2]);
    //     ezSetSpriteCollisionAsTrigger(b); /* MULTIPLE OLUNCA ABORT VERIYOR */
    // }
}

void OnReload(struct ball *ball, struct EZSprite *sprite) {
    ball->sprite       = sprite;
    ball->speed        = 0.5f;
    ball->bull_counter = 0;
    printf("Start: %s\n", ezGetSpriteName(sprite));
}

void OnUpdate(struct ball *ball) {
    pollInput((struct ball *)ball);
}

size_t GetInstanceSize() {
    printf("size: %zu\n", sizeof(struct ball));
    return sizeof(struct ball);
}

#ifdef __cplusplus
}
#endif