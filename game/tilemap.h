#ifndef TILEMAP_H
#define TILEMAP_H

typedef struct {
    int width;
    int height;

    char** tiles;
} TileMap;

TileMap tilemap_create(int width, int height);

TileMap tilemap_load(const char* path);

int tilemap_is_walkable(TileMap* map, int x, int y);

void tilemap_destroy(TileMap* map);

#endif