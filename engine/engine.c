#include "engine.h"
#include "input.h"
#include "renderer.h"
#include "timer.h"

static int running = 1;

void engine_init() {
    renderer_init();
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

}