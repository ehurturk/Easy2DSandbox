#include <iostream>
#include <string>
#include "Easy2D/input.h"
#include "Easy2D/sprite.h"

#define EZ_DEBUG_ENABLED
#include <Easy2D/easy2d.h>

void init();
void update();
void destroy();
void pollInput();

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
    ezToggleVSync(1);
    app->window   = ezCreateWindow("Easy2D Sandbox", 800, 600, 0);
    scene         = ezCreateScene();
    EZCamera *cam = ezCreateCamera(EZ_ORTHOGRAPHIC);
    ezAddToScene(scene, (void *)cam, EZ_CAMERA);

    /* Create a sprite with default shader which implements proj and model matrices by default */
    sprite = ezSquareSprite(400, 300, 0, 100, 100); /* pos x, pos y, width, height */

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
        pollInput();
        ezSetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);
        ezClearFrame();

        /* FPS */
        float fps = ezGetFPS();
        std::string title;
        title = std::to_string(fps).substr(0, std::to_string(fps).find(".") + 3);
        title = "FPS: " + title;
        std::cout << "Pos: (" << ezGetSpriteTransform(sprite)->position[0] << ", " << ezGetSpriteTransform(sprite)->position[1] << "), Scale: (" << ezGetSpriteTransform(sprite)->scale[0] << ", " << ezGetSpriteTransform(sprite)->scale[1] << "), Rot: (" << ezGetSpriteTransform(sprite)->rotation[2] << ")" << std::endl;
        ezSetWindowTitle(app->window, title.c_str());
        ezRenderScene(scene);
        ezUpdateWindow(app->window);
    }
}

void destroy() {
    ezFreeApp(app); /* deallocate the app */
    ezDestroyScene(scene);
}

void pollInput() {
    if (glfwGetKey(ezGetNativeWindow(app->window), GLFW_KEY_LEFT) == GLFW_PRESS) {
        ezRotateSprite(sprite, -10);
    }

    if (glfwGetKey(ezGetNativeWindow(app->window), GLFW_KEY_RIGHT) == GLFW_PRESS) {
        ezRotateSprite(sprite, 10);
    }

    const float speed = 10.0f;
    if (glfwGetKey(ezGetNativeWindow(app->window), EZ_KEY_W) == GLFW_PRESS) {
        vec3 t;
        t[0] = 0.0f;
        t[1] = -5.0f * speed;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }

    if (glfwGetKey(ezGetNativeWindow(app->window), EZ_KEY_A) == GLFW_PRESS) {
        vec3 t;
        t[0] = -5.0f * speed;
        t[1] = 0.0f;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }

    if (glfwGetKey(ezGetNativeWindow(app->window), EZ_KEY_S) == GLFW_PRESS) {
        vec3 t;
        t[0] = 0.0f;
        t[1] = 5.0f * speed;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }

    if (glfwGetKey(ezGetNativeWindow(app->window), EZ_KEY_D) == GLFW_PRESS) {
        vec3 t;
        t[0] = 5.0f * speed;
        t[1] = 0.0f;
        t[2] = 0.0f;
        ezTranslateSprite(sprite, t);
    }
}

void keyInput(int key, int action) {
    if (key == GLFW_KEY_ESCAPE && action == EZ_KEY_CLICK) {
        ezCloseWindow(app->window);
    }

    if (key == EZ_KEY_C && action == EZ_KEY_CLICK) {
        vec3 xyz;
        xyz[0] = 1.5f;
        xyz[1] = 1.0f;
        xyz[2] = 1.0f;
        ezScaleSprite(sprite, xyz);
    }

    if (key == EZ_KEY_O && action == EZ_KEY_CLICK) {
        ezSetSpritePosition(sprite, 400, 300);
        /* TODO
        ezSetSpriteRotation(sprite, 0);
        */
    }
}