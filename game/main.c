#include <stdio.h>

#include "../engine/engine.h"
#include "../engine/input.h"
#include "../engine/renderer.h"
#include "../engine/timer.h"

#include "entity.h"

Entity player = {
    5,
    5,
    'P'
};

void game_update() {
    if(key_down(KEY_W)) player.y--;
    if(key_down(KEY_S)) player.y++;
    if(key_down(KEY_A)) player.x--;
    if(key_down(KEY_D)) player.x++;
}

void game_render() {
    renderer_draw_entity(&player);
}

int main() {
    engine_init();

    while(1) {
        input_update();
        game_update();
        renderer_clear();
        game_render();
        renderer_present();
        timer_update();
    }

    engine_shutdown();

    return 0;
}