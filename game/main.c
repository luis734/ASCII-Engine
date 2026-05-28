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

int running = 1;

void game_update() {

    int nextX = player.x;
    int nextY = player.y;

    if(key_down(KEY_W)) nextY--;
    if(key_down(KEY_S)) nextY++;
    if(key_down(KEY_A)) nextX--;
    if(key_down(KEY_D)) nextX++;

    // Verifica las colisiones con tiles de pared (#)
    if(tilemap_is_walkable(&map, nextX, nextY)) {
        player.x = nextX;
        player.y = nextY;
    }

    if(key_down(KEY_ESCAPE)) running = 0;
}

void game_render() {
    renderer_draw_map(&map);
    renderer_draw_entity(&player);
}

int main() {
    EngineConfig screenConfig = {
        28,
        11
    };
    
    engine_init(screenConfig);
    map = tilemap_load("maps/level1.txt"); // Creamos un nuevo mapa por lo que hay que eliminarlo al terminar de usarlo

    while(running) {
        input_update(); // Verifica las entradas
        game_update(); // Actualiza las variables del juego
        renderer_clear(); // Limpia la pantalla
        game_render(); // Escribe el nuevo estado del juego en la pantalla
        renderer_present(); // Dibuja la pantalla nuevamente
        timer_update(); // Agrega un delay para evitar abusar del procesador
    }

    tilemap_destroy(&map); // Destruimos el tilemap para evitar memory leak
    engine_shutdown(); // Limpia los valores de la pantalla

    return 0;
}