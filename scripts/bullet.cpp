#include <iostream>
#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"
#include "bullet.h"

static const float speed = 10.0f;
static EZSprite *tank1;

static void pollInput(int key, int action) {
}

static void start(struct EZSprite *parent) {
    std::cout << "Starting sprite: " << ezGetSpriteName(parent) << std::endl;
}

static void update(struct EZSprite *parent) {
    EZ_VEC3(t, 0.0f, -1.5f * speed, 0.0f);
    ezTranslateSprite(parent, t, EZ_LOCAL_REF);

    if (ezGetSpriteTransform(parent)->position[0] < 0.0f) {
        ezDestroySprite(parent); /* PROBLEM */
    }
}

static void destroy(struct EZSprite *parent) {
    printf("Destroying bullet script.\n");
}

/* IMPORTANT MACRO: Defines the init function of this script */
/* Note that the macro parameter must be the same as the extern struct you have defined in the corresponding header file. */
EZ_INIT_SCRIPT(newscript, start, update, destroy, pollInput);