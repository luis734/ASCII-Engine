#ifndef SCENE_H
#define SCENE_H

typedef struct {

    void (*update)();

    void (*render)();

} Scene;

void scene_set(Scene* scene);

void scene_update();

void scene_render();

#endif