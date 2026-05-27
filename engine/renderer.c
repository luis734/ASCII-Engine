#include <stdio.h>
#include <stdlib.h>
#include "renderer.h"

static int screenWidth;
static int screenHeight;

static char screen[100][100];

void renderer_init(int width, int height) {
    screenWidth = width;
    screenHeight = height;
}

void renderer_clear() {
    for(int y = 0; y < screenHeight; y++) {
        for(int x = 0; x < screenWidth; x++) {
            screen[y][x] = '.';
        }
    }
}

void renderer_draw_char(int x, int y, char c) {
    if(x < 0 || x >= screenWidth) return;
    if(y < 0 || y >= screenHeight) return;

    screen[y][x] = c;
}

void renderer_present() {
    system("cls");

    for(int y = 0; y < screenHeight; y++) {
        for(int x = 0; x < screenWidth; x++) {
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