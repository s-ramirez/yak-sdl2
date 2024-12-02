#include "common/input.hpp"
#include <iostream>
using namespace Yak;

namespace {
    InputState empty_input_state;
}

InputState Yak::Input::state;
InputState Yak::Input::last_state;

void Input::init() {
    state = empty_input_state;
    last_state = empty_input_state;
}

void Input::step() {
    // Update state
    Input::last_state = Input::state;

    // Clear state of keys, will be updated by events
    // for(int i = 0; i < Input::max_keyboard_keys; i++) {
    //     Input::state.keyboard.pressed[i] = false;
    //     Input::state.keyboard.released[i] = false;
    // }
}

bool Input::pressed(Key key) {
    int index = (int)key;
    std::cout << "Pressed: " << state.keyboard.pressed[index] << std::endl;
    return index >= 0 && index < Input::max_keyboard_keys && state.keyboard.pressed[index];
}

bool Input::down(Key key) {
    int index = (int)key;
    return index >= 0 && index < Input::max_keyboard_keys && state.keyboard.down[index];
}

bool Input::released(Key key) {
    int index = (int)key;
    return index >= 0 && index < Input::max_keyboard_keys && state.keyboard.released[index];
}   

void KeyboardState::on_press(Key key) {
    int index = (int)key;
    if (index >= 0 && index < Input::max_keyboard_keys) {
        pressed[index] = true;
        down[index] = true;
    }
}

void KeyboardState::on_release(Key key) {
    int index = (int)key;
    if (index >= 0 && index < Input::max_keyboard_keys) {
        released[index] = true;
        down[index] = false;
    }
}

bool KeyboardState::ctrl() {
    return down[(int)Key::LeftControl] || down[(int)Key::RightControl];
}

bool KeyboardState::shift() {
    return down[(int)Key::LeftShift] || down[(int)Key::RightShift];
}

bool KeyboardState::space() {
    return down[(int)Key::Space];
}