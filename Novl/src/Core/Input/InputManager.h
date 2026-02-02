/**
 * < Novl Engine > InputManager.h
 * Author: DeckardZ46
 * Date: 2025/08/30
 * Note: Input manager of Novl Engine.
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include "KeyInput.h"
#include "MouseInput.h"

namespace Novl {
struct InputState {
    bool keys[MAX_KEYCODE_COUNT] = {false};     
    bool prevKeys[MAX_KEYCODE_COUNT] = {false}; 
    bool mouseButtons[MAX_MOUSEBUTTON_COUNT] = {false};
    bool prevMouseButtons[MAX_MOUSEBUTTON_COUNT] = {false};
    float mouseX = 0;
    float mouseY = 0;
    float prevMouseX = 0;
    float prevMouseY = 0;
};

class InputManager {
  public:
    InputManager() = default;
    ~InputManager();
    void init();
    void shutdown();

    void update();
    bool isKeyPressed(NovlKeyCode key);
    bool isMouseButtonPressed(NovlMouseButton button);

    void onKeyPress(NovlKeyCode key);
    void onKeyRelease(NovlKeyCode key);
    void onMouseButtonPress(NovlMouseButton button);
    void onMouseButtonRelease(NovlMouseButton button);
    void onMouseMove(float xPos, float yPos);
    void onMouseScroll(float xOffset, float yOffset);

  private:
    InputState m_inputState;
};
} // namespace Novl
