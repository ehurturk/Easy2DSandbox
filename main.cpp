#include <iostream>
#include <string>
#include "Easy2D/sprite.h"

#define EZ_DEBUG_ENABLED
#include <Easy2D/easy2d.h>

#include "scripts/gameobject.h"
#include "scripts/script1.h"
#include "scripts/script2.h"
#include "scripts/script3.h"

void init();
void update();
void destroy();

void keyInput(int key, int action);

EZApplication *app;

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
    app->window = ezCreateWindow("Easy2D Sandbox", 800, 800, 0);

    ezCreateScene();

    EZCamera *cam = ezCreateCamera(EZ_ORTHOGRAPHIC);
    ezAddToScene((void *)cam, EZ_CAMERA);

    /* Create a sprite with default shader which implements proj and model matrices by default */
    EZSprite *sprite  = ezSquareSprite("def_sprite", 400, 300, 0, 60, 60);          /* pos x, pos y, width, height */
    EZSprite *sprite2 = ezSquareSprite("tank2", 100, 200, 0, 60, 60);               /* create a normal square sprite that is renderable */
    EZSprite *sprite3 = ezSquareSprite("tank3", 300, 200, 0, 60, 60);               /* create a normal square sprite that is renderable */
    EZSprite *gameobj = ezEmptySprite(EZ_EMPTY_GAMEOBJ, "gameobject", 200, 200, 0); /* create an empty gameobject with no purpose - just like html divs */

    /* Create shaders & texture - and bind them to the sprite */
    EZShader *shader = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                              (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(sprite, shader);

    EZShader *shader2 = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                               (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(sprite2, shader2);

    EZTexture *tex1 = ezLoadTexture("../res/tank.png");
    ezSetSpriteTexture(sprite, tex1);

    EZTexture *tex2 = ezLoadTexture("../res/tank.png");
    ezSetSpriteTexture(sprite2, tex2);

    /* Initialize the scripts and then add them to their parent sprites */
    EZ_INITIALIZE_SCRIPT(gameobject);
    EZ_INITIALIZE_SCRIPT(script1);
    EZ_INITIALIZE_SCRIPT(script2);

    /* The script parameters must have the same name as the macro parameters above */
    ezSpriteAddScript(sprite, script1);
    ezSpriteAddScript(gameobj, gameobject);
    ezSpriteAddScript(sprite2, script2);

    ezAddToScene((void *)sprite, EZ_GAMEOBJS);
    ezAddToScene((void *)sprite2, EZ_GAMEOBJS);
    ezAddToScene((void *)gameobj, EZ_GAMEOBJS);
    ezAddToScene((void *)sprite3, EZ_GAMEOBJS);

    ezStartScene();
}

void update() {
    while (!ezIsWindowOpen(app->window)) {
        ezSetBackgroundColor(0.3f, 0.1f, 0.4f, 1.0f);
        ezClearFrame();

        /* first update then render */
        ezUpdateScene();

        /* FPS */
        float fps         = ezGetFPS();
        std::string title = "FPS: " + std::to_string(fps).substr(0, std::to_string(fps).find(".") + 3);

        ezSetWindowTitle(app->window, title.c_str());
        ezRenderScene();
        ezUpdateWindow(app->window);
    }
}

void destroy() {
    ezFreeApp(app); /* deallocate the app */
    ezDestroyScene();
    /* Free all scripts */
    free(script1);
    free(script2);
    free(script3);
    free(gameobject);
}

void keyInput(int key, int action) {
    if (key == GLFW_KEY_ESCAPE && action == EZ_KEY_CLICK) {
        ezCloseWindow(app->window);
    }

    if (key == EZ_KEY_G && action == EZ_KEY_CLICK) {
        struct EZSprite *sprite = ezSquareSprite("aa", 100, 200, 0, 30, 30);
        ezInstantiateSprite((const void *)sprite, 400, 300);
    }
}