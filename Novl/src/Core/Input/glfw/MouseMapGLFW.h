/**
 * < Novl Engine > MouseMapGLFW.h
 * Author: DeckardZ46
 * Date: 2025/10/28
 * Note: Mouse mapping between Novl Engine and GLFW
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

#include "Core/Input/MouseInput.h"
#include <glfw3.h>

namespace Novl{
[[nodiscard]] inline constexpr NovlMouseButton GLFWMouseButtonToNovlMouseButton(int glfwButton) noexcept{
    switch (glfwButton) {
        case GLFW_MOUSE_BUTTON_LEFT:      return NovlMouseButton::Left;
        case GLFW_MOUSE_BUTTON_RIGHT:     return NovlMouseButton::Right;
        case GLFW_MOUSE_BUTTON_MIDDLE:    return NovlMouseButton::Middle;
        case GLFW_MOUSE_BUTTON_4:         return NovlMouseButton::ButtonX1;
        case GLFW_MOUSE_BUTTON_5:         return NovlMouseButton::ButtonX2;
        default:                          return NovlMouseButton::AnyMouseButton;
    }
}
} // namespace Novl 