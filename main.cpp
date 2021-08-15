#include <iostream>
#include <string>
#include "Easy2D/aabb.h"
#include "Easy2D/input.h"
#include "Easy2D/scene.h"
#include "Easy2D/sprite.h"
#include "Easy2D/stl/vector.h"

#define EZ_DEBUG_ENABLED
#include <Easy2D/easy2d.h>

void init();
void update();
void destroy();

void keyInput(int key, int action);

EZApplication *app;
EZScene *scene;
EZSprite *sprite;
EZSprite *sprite2;

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
    // ezToggleVSync(1);
    app->window   = ezCreateWindow("Easy2D Sandbox", 800, 600, 0);
    scene         = ezCreateScene();
    EZCamera *cam = ezCreateCamera(EZ_ORTHOGRAPHIC);
    ezAddToScene(scene, (void *)cam, EZ_CAMERA);

    /* Create a sprite with default shader which implements proj and model matrices by default */
    sprite  = ezSquareSprite("def_sprite", 400, 300, 0, 100, 100); /* pos x, pos y, width, height */
    sprite2 = ezSquareSprite("def_sprite2", 100, 200, 0, 50, 50);

    /* Create shaders & texture - and bind them to the sprite */
    EZShader *shader = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                              (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(sprite, shader);

    EZTexture *tex1 = ezLoadTexture("../res/tank.png");
    ezSetSpriteTexture(sprite, tex1);

    /* Add scripts that are going to be compiled at run time - could be slow but this was the only solution that worked */
    ezSpriteAddScript(sprite2, "script2.c", "script2");
    ezSpriteAddScript(sprite, "script1.c", "script1");

    ezAddToScene(scene, (void *)sprite, EZ_GAMEOBJS);
    ezAddToScene(scene, (void *)sprite2, EZ_GAMEOBJS);

    ezStartScene(scene);
}

void update() {
    while (!ezIsWindowOpen(app->window)) {
        ezSetBackgroundColor(0.3f, 0.1f, 0.4f, 1.0f);
        ezClearFrame();
        /* first update then render */
        ezUpdateScene(scene);
        /* FPS */
        float fps = ezGetFPS();
        std::string title;
        title = std::to_string(fps).substr(0, std::to_string(fps).find(".") + 3);
        title = "FPS: " + title;

        /* To test collision */
        /*
        if (ezCheckSpriteCollision(sprite, sprite2)) {
            std::cout << "COLLISION!!" << std::endl;
        } else {
            std::cout << "NO COLLISION!!" << std::endl;
        }
        */

        ezSetWindowTitle(app->window, title.c_str());
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

    if (key == EZ_KEY_G && action == EZ_KEY_CLICK) {
        struct EZSprite *sprite = ezSquareSprite("aa", 100, 200, 0, 30, 30);
        ezInstantiateSprite(scene, (const void *)sprite, 400, 300);
    }

    if (key == EZ_KEY_O && action == EZ_KEY_CLICK) {
        ezSetSpritePosition(sprite, 400, 300);
    }
}