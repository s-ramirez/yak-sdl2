#pragma once
#include <SDL.h>

#define KEY_DEFINITIONS \
    DEFINE_KEY(A, 4) \
    DEFINE_KEY(D, 7) \
    DEFINE_KEY(S, 22) \
    DEFINE_KEY(W, 26) \
    DEFINE_KEY(LeftControl, 29) \
    DEFINE_KEY(RightControl, 30) \
    DEFINE_KEY(LeftShift, 42) \
    DEFINE_KEY(RightShift, 54) \
    DEFINE_KEY(Space, 57)

namespace Yak {
    enum class Key 
    {
        #define DEFINE_KEY(name, value) name = value,
        KEY_DEFINITIONS
        #undef DEFINE_KEY
    };


    namespace Input {
        const int max_keyboard_keys = 512;
    }   

    // Keyboard state
    struct KeyboardState {
        bool pressed[Input::max_keyboard_keys];
        bool down[Input::max_keyboard_keys];
        bool released[Input::max_keyboard_keys];

        bool ctrl();
        bool shift();
        bool space();

        void on_press(Key key);
        void on_release(Key key);
    };

    // Input state of keyboard
    struct InputState {
        KeyboardState keyboard;
    };

    namespace Input {
        extern InputState state;
        extern InputState last_state;

        // Check if a key was pressed   
        bool pressed(Key key);

        // Check if a key is down
        bool down(Key key);

        // Check if a key was released
        bool released(Key key);

        // Functions
        void init();
        void step();
    };
}