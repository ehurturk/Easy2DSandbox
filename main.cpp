#include <iostream>
#include "Easy2D/camera.h"
#include "Easy2D/input.h"
#include "Easy2D/sprite.h"

#define EZ_DEBUG_ENABLED
#include <Easy2D/easy2d.h>

void init();
void update();
void destroy();

void keyInput(int key, int action);

EZApplication *app;
EZScene *scene;
EZSprite *sprite;

int main() {
    app = ezCreateApplication();
    /* After creating the application, you need to register it to Easy2D */
    ezRegisterAsApplication(app);
    /* The bind the functions */
    ezBindAppInitCallback(init);
    ezBindAppUpdateCallback(update);
    ezBindAppDestroyCallback(destroy);
    ezStart();

    return 0;
}

void init() {
    ezBindKeyInputFunc(keyInput);
    app->window   = ezCreateWindow("Easy2DSandbox", 800, 600);
    scene         = ezCreateScene();
    EZCamera *cam = ezCreateCamera(EZ_ORTHOGRAPHIC);
    ezAddToScene(scene, (void *)cam, EZ_CAMERA);

    /* Create a sprite with default shader which implements proj and model matrices by default */
    sprite = ezSquareSprite(400, 300, 0, 200, 200);

    /* Create shaders & texture - and bind them to the sprite */

    EZShader *shader = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                              (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(sprite, shader);

    EZTexture *tex1 = ezLoadTexture("../res/barack.jpeg");
    ezSetSpriteTexture(sprite, tex1);

    ezAddToScene(scene, (void *)sprite, EZ_GAMEOBJECT);
}

void update() {
    while (!ezIsWindowOpen(app->window)) {
        ezSetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);
        ezClearFrame();

        ezRenderScene(scene);
        ezUpdateWindow(app->window);
    }
}

void destroy() {
    ezFreeApp(app); /* deallocate the app */
    ezDestroyScene(scene);
}

void keyInput(int key, int action) {
    if (key == GLFW_KEY_ESCAPE && action == EZ_KEY_CLICK) {
        ezCloseWindow(app->window);
    }

    if (key == EZ_KEY_W && (action == EZ_KEY_HOLD || action == EZ_KEY_CLICK)) {
        vec3 t;
        t[0] = 0.0f;
        t[1] = -10.0f;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }
    if (key == EZ_KEY_A && (action == EZ_KEY_HOLD || action == EZ_KEY_CLICK)) {
        vec3 t;
        t[0] = -10.0f;
        t[1] = 0.0f;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }
    if (key == EZ_KEY_S && (action == EZ_KEY_HOLD || action == EZ_KEY_CLICK)) {
        vec3 t;
        t[0] = 0.0f;
        t[1] = 10.0f;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }
    if (key == EZ_KEY_D && (action == EZ_KEY_HOLD || action == EZ_KEY_CLICK)) {
        vec3 t;
        t[0] = 10.0f;
        t[1] = 0.0f;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }
}