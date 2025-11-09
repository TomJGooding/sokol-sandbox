#define SOKOL_IMPL
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"

static sg_pass_action pass_action;

static void init(void) {
    sg_setup(&(sg_desc){
        .environment = sglue_environment(),
    });

    // a pass action to clear framebuffer to red
    pass_action = (sg_pass_action){
        .colors[0] = {
            .load_action=SG_LOADACTION_CLEAR,
            .clear_value={1.0f, 0.0f, 0.0f, 1.0f}
        }
    };
}

static void frame(void) {
    sg_begin_pass(&(sg_pass){
        .action = pass_action,
        .swapchain = sglue_swapchain()
    });

    sg_end_pass();
    sg_commit();
}

static void cleanup(void) {
    sg_shutdown();
}

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
