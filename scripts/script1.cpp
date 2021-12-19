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

static struct ball *m_instance;

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

// /* bound function for handling single click input */
// static void inputfun(int key, int action) {
//     if (ezIsKeyDown(GLFW_KEY_LEFT_SHIFT)) {
//         m_instance->speed = 1.0f;
//     } else {
//         m_instance->speed = 0.5f;
//     }

//     /* solve single clicks */
//     if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
//         /* instantiate bullet */
//         struct EZSprite *b = createBullet();
//         ezInstantiateSprite((const void *)b, ezGetSpriteTransform(m_instance->sprite)->position[0], ezGetSpriteTransform(m_instance->sprite)->position[1], ezGetSpriteTransform(m_instance->sprite)->rotation[2]);
//         ezSetSpriteCollisionAsTrigger(b); /* MULTIPLE OLUNCA ABORT VERIYOR */
//     }
// }

// /* Input function for continous inputs (I just couldn't solve single click problem, looks awkward I know */
// static void pollInput(struct ball *parent) {
//     if (ezIsKeyDown(EZ_KEY_A)) {
//         ezRotateSprite(parent->sprite, -4);
//     }

//     if (ezIsKeyDown(EZ_KEY_F))
//         ezDestroySprite(parent->sprite);

//     if (ezIsKeyDown(EZ_KEY_D)) {
//         ezRotateSprite(parent->sprite, 4);
//     }

//     if (ezIsKeyDown(EZ_KEY_W)) {
//         EZ_VEC3(t, 0.0f, -5.0f * m_instance->speed, 0.0f);
//         ezTranslateSprite(parent->sprite, t, EZ_LOCAL_REF);
//     }

//     if (ezIsKeyDown(EZ_KEY_S)) {
//         EZ_VEC3(t, 0.0f, 5.0f * m_instance->speed, 0.0f);
//         ezTranslateSprite(parent->sprite, t, EZ_LOCAL_REF);
//     }
// }

void OnReload(void *instance, struct EZSprite *parent) {
    m_instance         = (struct ball *)instance;
    m_instance->sprite = parent;
    printf("Start YYY: %s\n", ezGetSpriteName(m_instance->sprite));
}

void OnUpdate() {
    // pollInput(m_instance);
}

size_t GetInstanceSize() { return sizeof(struct ball); }

#ifdef __cplusplus
}
#endif