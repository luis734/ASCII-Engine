#include "engine.h"
#include "input.h"
#include "renderer.h"
#include "timer.h"

static int running = 1;

void engine_init(EngineConfig config) {
    renderer_init(config.width, config.height);
    timer_init();
}

void engine_run() {
    while(running) {
        input_update();
        renderer_clear();
        renderer_present();
        timer_update();
    }
}

void engine_stop() {
    running = 0;
}

void engine_shutdown() {
    renderer_shutdown();
}