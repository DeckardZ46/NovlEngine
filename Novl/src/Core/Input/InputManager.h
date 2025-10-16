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
class InputListener {
public:
    // InputListener();
    ~InputListener() = default;

    virtual void OnKey(NovlKeyCode code, bool pressed) {}
    virtual void OnMouseMove(float x, float y) {}
    virtual void OnMouseButton(NovlMouseButton btn, bool pressed) {}
    virtual void OnScroll(float dx, float dy) {}
};

class InputManager {
  public:
    void init();
    void shutdown();

    void AddListener(InputListener *listener);
    void RemoveListener(InputListener *listener);

  private:
    
    
};
} // namespace Novl
