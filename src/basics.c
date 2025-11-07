#define SOKOL_IMPL
#include "sokol_app.h"

sapp_desc sokol_main(int argc, char *argv[]) {
    return (sapp_desc){
        .window_title = "Basic Sokol App",
        .width = 800,
        .height = 600,
    };
}
