#include <stdio.h>

#include "../engine/engine.h"
#include "../engine/input.h"
#include "../engine/renderer.h"
#include "../engine/timer.h"

#include "entity.h"
#include "tilemap.h"

Entity player = {
    5,
    5,
    'P'
};

TileMap map;

void game_update() {
    if(key_down(KEY_W)) player.y--;
    if(key_down(KEY_S)) player.y++;
    if(key_down(KEY_A)) player.x--;
    if(key_down(KEY_D)) player.x++;
}

void game_render() {
    renderer_draw_map(&map);
    renderer_draw_entity(&player);
}

int main() {
    EngineConfig screenConfig = {
        20,
        10
    };
    
    engine_init(screenConfig);
    map = tilemap_create(20, 10);

    int running = 1;

    while(running) {
        input_update();
        if (key_down(KEY_ESCAPE)) running = 0;
        game_update();
        renderer_clear();
        game_render();
        renderer_present();
        timer_update();
    }

    engine_shutdown();

    return 0;
}