#define SOKOL_IMPL
#include "sokol_app.h"

static void init(void) {}

static void frame(void) {}

static void cleanup(void) {}

static void event(const sapp_event *event) {
    if (event->type == SAPP_EVENTTYPE_KEY_DOWN) {
        if (event->key_code == SAPP_KEYCODE_ESCAPE) {
            sapp_quit();
        }
    }
}

sapp_desc sokol_main(int argc, char *argv[]) {
    return (sapp_desc){
        .window_title = "Basic Sokol App",
        .width = 800,
        .height = 600,
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
    };
}
