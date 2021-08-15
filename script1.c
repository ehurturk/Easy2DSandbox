#include <stdio.h>

#include <Easy2D/easy2d.h>
#include <Easy2D/sprite.h>

struct EZSprite *sprite;

void start(struct EZSprite *sprite) {
    sprite = sprite;
    printf("Start sprite: %s\n", ezGetSpriteName(sprite));
}

void update() {
    printf("update\n");
}