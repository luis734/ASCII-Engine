#include <stdio.h>
#include <stdlib.h>
#include "renderer.h"

static char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

void renderer_init() {

}

void renderer_clear() {
    for(int y = 0; y < SCREEN_HEIGHT; y++) {
        for(int x = 0; x < SCREEN_WIDTH; x++) {
            screen[y][x] = '.';
        }
    }
}

void renderer_draw_char(int x, int y, char c) {
    if(x < 0 || x >= SCREEN_WIDTH) return;
    if(y < 0 || y >= SCREEN_HEIGHT) return;

    screen[y][x] = c;
}

void renderer_present() {
    system("cls");

    for(int y = 0; y < SCREEN_HEIGHT; y++) {
        for(int x = 0; x < SCREEN_WIDTH; x++) {
            printf("%c", screen[y][x]);
        }

        printf("\n");
    }
}

void renderer_draw_entity(Entity* entity) {
    renderer_draw_char(
        entity->x,
        entity->y,
        entity->sprite
    );
}

void renderer_draw_text(int x, int y, const char* text) {
    int i = 0;

    while(text[i] != '\0') {
        renderer_draw_char(x + i, y, text[i]);
        i++;
    }
}