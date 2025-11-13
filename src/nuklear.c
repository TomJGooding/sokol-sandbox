#define SOKOL_IMPL
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"

// Include nuklear.h before sokol_nuklear.h
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_IMPLEMENTATION
#include "nuklear.h"
#include "sokol_nuklear.h"

static void draw_ui(struct nk_context *ctx) {
    nk_style_hide_cursor(ctx);

    nk_flags win_flags = NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_TITLE;

    if (nk_begin(ctx, "Window", nk_rect(50, 50, 220, 150), win_flags)) {
        nk_layout_row_dynamic(ctx, 30, 1);
        nk_label(ctx, "Hello Nuklear!", NK_TEXT_CENTERED);
        if (nk_button_label(ctx, "Button")) {
            // event handling
            fprintf(stdout, "Button pressed\n");
        }
    }

    nk_end(ctx);
}

static void init(void) {
    sg_setup(&(sg_desc){.environment = sglue_environment()});

    snk_setup(&(snk_desc_t){
        .enable_set_mouse_cursor = true,
        .dpi_scale = sapp_dpi_scale()
    });
}

static void frame(void) {
    struct nk_context *ctx = snk_new_frame();

    draw_ui(ctx);

    sg_begin_pass(&(sg_pass){
        .action = {
            .colors[0] = {
                .load_action = SG_LOADACTION_CLEAR, 
                .clear_value = {0.0f, 0.0f, 0.0f, 1.0f}
            }},
            .swapchain = sglue_swapchain()
    });

    snk_render(sapp_width(), sapp_height());

    sg_end_pass();
    sg_commit();
}

static void cleanup(void) {
    snk_shutdown();
    sg_shutdown();
}

static void event(const sapp_event *event) {
    if (!snk_handle_event(event)) {
        // event should be handled by the app
    }
}

sapp_desc sokol_main(int argc, char *argv[]) {
    return (sapp_desc){
        .window_title = "Nuklear App",
        .width = 800,
        .height = 600,
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
    };
}
