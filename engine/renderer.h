#ifndef RENDERER_H
#define RENDERER_H

#include "../game/entity.h"

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 10

void renderer_init();

void renderer_clear();

void renderer_draw_char(int x, int y, char c);

void renderer_draw_entity(Entity* entity);

void renderer_present();

#endif