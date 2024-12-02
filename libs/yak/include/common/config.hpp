#pragma once

namespace Yak {
    struct Config {
        const char *name = "MyYakGame";
        int width = 320;
        int height = 240;
        int framerate = 60;

        // Add callbacks
        void (*on_init)();
        void (*on_update)();
        void (*on_render)();
    };
}
