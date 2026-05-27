#ifndef ENGINE_H
#define ENGINE_H

typedef struct {
    int width;
    int height;
} EngineConfig;

void engine_init(EngineConfig config);
void engine_run();
void engine_stop();
void engine_shutdown();

#endif