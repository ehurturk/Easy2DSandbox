/*
	This file is a simple script source template that ca nbe used inside Easy2D applications.
	Please pay attention to comments, since they are important.
*/

#include <iostream>
#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"
#include "bullet.h"

static const float speed = 10.0f;

static void pollInput(struct EZSprite *sprite) {
    EZSprite *sprite1 = (EZSprite *)ezFindSpriteWithName("def_sprite");
    if (sprite1 != NULL) {
        ezSetSpriteRotation(sprite, ezGetSpriteTransform(sprite1)->rotation[2]);
    }

    EZ_VEC3(t, 0.0f, -1.5f * speed, 0.0f);
    ezTranslateSprite(sprite, t, EZ_LOCAL_REF);
}

static void start(struct EZSprite *parent) {
    std::cout << "Starting sprite: " << ezGetSpriteName(parent) << std::endl;
}

static void update(struct EZSprite *parent) {
    // std::cout << "Updating sprite: " << ezGetSpriteName(parent) << " (" << ezGetSpriteTransform(parent)->position[0] << ", " << ezGetSpriteTransform(parent)->position[1] << ", " << ezGetSpriteTransform(parent)->rotation[2] << ")" << std::endl;
    pollInput(parent);
}

static void destroy(struct EZSprite *parent) {
    free(newscript);
    printf("PROBLEM HERE - THE PROBLEM IS BIRCOK KERE SPACE A BASTIGIM ICIN BIRCOK KEZ INSTANTIATE EDIYOR SONRA BI TANE FREELEDIGI ICIN ABORT VERIYOR\n");
}
/* IMPORTANT MACRO: Defines the init function of this script */
/* Note that the macro parameter must be the same as the extern struct you have defined in the corresponding header file. */
EZ_INIT_SCRIPT(newscript);