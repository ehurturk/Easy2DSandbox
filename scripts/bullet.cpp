/*
	This file is a simple script source template that ca nbe used inside Easy2D applications.
	Please pay attention to comments, since they are important.
*/

#include <iostream>
#include <Easy2D/easy2d.h>
#include "Easy2D/sprite.h"
#include "bullet.h"

static void start(struct EZSprite *parent) {
    std::cout << "Starting sprite: " << ezGetSpriteName(parent) << std::endl;
}

static void update(struct EZSprite *parent) {
    // std::cout << "Updating sprite: " << ezGetSpriteName(parent) << std::endl;
}

static void destroy(struct EZSprite *parent) {
    free(newscript);
    printf("PROBLEM HERE - THE PROBLEM IS BIRCOK KERE SPACE A BASTIGIM ICIN BIRCOK KEZ INSTANTIATE EDIYOR SONRA BI TANE FREELEDIGI ICIN ABORT VERIYOR\n");
}
/* IMPORTANT MACRO: Defines the init function of this script */
/* Note that the macro parameter must be the same as the extern struct you have defined in the corresponding header file. */
EZ_INIT_SCRIPT(newscript);