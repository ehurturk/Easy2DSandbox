#include <iostream>
#include <string>
#include "Easy2D/sprite.h"

#define EZ_DEBUG_ENABLED
#include <Easy2D/easy2d.h>

#include "scripts/gameobject.h"
#include "scripts/script1.h"
#include "scripts/script2.h"
#include "scripts/script3.h"
#include "scripts/bullet.h"

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
    EZSprite *sprite  = ezSquareSprite("def_sprite", 400, 300, 0, 60, 60); /* tank */
    EZSprite *sprite2 = ezSquareSprite("tank2", 100, 200, 0, 60, 60);      /* tank */
    EZSprite *sprite3 = ezSquareSprite("tank3", 300, 200, 0, 60, 60);      /* white square */
    // EZSprite *gameobj   = ezEmptySprite(EZ_EMPTY_GAMEOBJ, "gameobject", 200, 200, 0); /* create an empty gameobject with no purpose - just like html divs */
    EZSprite *newsprite = ezSquareSprite("newsprite", 250, 250, 0, 40, 40); /* bullet */

    /* Create shaders & texture - and bind them to the sprite */
    EZShader *shader = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                              (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(sprite, shader);

    EZShader *shader2 = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                               (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(sprite2, shader2);

    EZShader *shader3 = ezDirectShaderPipeline(2, (EZShaderInfo){.type = EZ_VERTEX_SHADER, .src = "../res/simple.vs"},
                                               (EZShaderInfo{.type = EZ_FRAGMENT_SHADER, .src = "../res/simple.fs"}));
    ezSetSpriteShader(newsprite, shader3);

    EZTexture *tex1 = ezLoadTexture("../res/tank.png");
    ezSetSpriteTexture(sprite, tex1);

    EZTexture *tex2 = ezLoadTexture("../res/tank.png");
    ezSetSpriteTexture(sprite2, tex2);

    EZTexture *tex3 = ezLoadTexture("../res/blt.png");
    ezSetSpriteTexture(newsprite, tex3);

    /* Initialize the scripts and then add them to their parent sprites */
    // EZ_INITIALIZE_SCRIPT(gameobject);
    EZ_INITIALIZE_SCRIPT(script1);
    EZ_INITIALIZE_SCRIPT(script2);
    EZ_INITIALIZE_SCRIPT(script3);
    EZ_INITIALIZE_SCRIPT(newscript);

    /* The script parameters must have the same name as the macro parameters above */
    ezSpriteAddScript(sprite, script1);
    // ezSpriteAddScript(gameobj, gameobject);
    ezSpriteAddScript(sprite2, script2);
    ezSpriteAddScript(newsprite, newscript); /* but don't add to the scene since its a prefab - will be instantiated later. */
    ezSpriteAddScript(sprite3, script3);     /* but don't add to the scene since its a prefab - will be instantiated later. */

    ezAddToScene((void *)sprite, EZ_GAMEOBJS);
    ezAddToScene((void *)sprite2, EZ_GAMEOBJS);
    // ezAddToScene((void *)gameobj, EZ_GAMEOBJS);
    ezAddToScene((void *)sprite3, EZ_GAMEOBJS);

    ezStartScene();
}

void update() {
    while (!ezIsWindowOpen(app->window)) {
        ezSetBackgroundColor(0.3f, 0.1f, 0.4f, 1.0f);
        ezClearFrame();

        /* first update then render */
        // printf("AAAB\n");
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
}

void keyInput(int key, int action) {
    if (key == GLFW_KEY_ESCAPE && action == EZ_KEY_CLICK) {
        ezCloseWindow(app->window);
    }
}