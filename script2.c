#include <stdio.h>

#include <Easy2D/easy2d.h>

void start(struct EZSprite *parent) {
    printf("Start sprite: %s\n", ezGetSpriteName(parent));
}

void update(struct EZSprite *parent) {
    printf("[%s]: (%f, %f) (%f, %f) (%f)\n", ezGetSpriteName(parent), ezGetSpriteTransform(parent)->position[0], ezGetSpriteTransform(parent)->position[1], ezGetSpriteTransform(parent)->scale[0], ezGetSpriteTransform(parent)->scale[1], ezGetSpriteTransform(parent)->rotation[2]);
}