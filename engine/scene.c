#include "scene.h"

static Scene* currentScene = 0;

void scene_set(Scene* scene) {
    currentScene = scene;
}

void scene_update() {
    if(currentScene && currentScene->update) {
        currentScene->update();
    }
}

void scene_render() {
    if(currentScene && currentScene->render) {
        currentScene->render();
    }
}