#include <stdlib.h>
#include "tilemap.h"

TileMap tilemap_create(int width, int height) {
    TileMap map;

    map.width = width;
    map.height = height;

    map.tiles = malloc(sizeof(char*) * height);

    for(int y = 0; y < height; y++) {
        map.tiles[y] = malloc(sizeof(char) * width);

        for(int x = 0; x < width; x++) {
            if(
                y == 0 ||
                y == height - 1 ||
                x == 0 ||
                x == width - 1
            ) {
                map.tiles[y][x] = '#';
            }
            else {
                map.tiles[y][x] = ' ';
            }
        }
    }

    return map;
}

int tilemap_is_walkable(TileMap* map, int x, int y) {
    if (x < 0 || x > map->width) {
        return 0;
    }

    if (y < 0 || y > map->height) {
        return 0;
    }

    if (map->tiles[y][x] == '#') {
        return 0;
    } 

    return 1;
}