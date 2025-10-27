/**
 * < Novl Engine > KeyMapGLFW.h
 * Author: DeckardZ46
 * Date: 2025/10/28
 * Note: Key mapping between Novl Engine and GLFW
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

#include "Core/Input/KeyInput.h"
#include <glfw3.h>

namespace Novl {
[[nodiscard]] inline constexpr NovlKeyCode GLFWKeyToNovlKeyCode(int glfwKey) noexcept{
    // A-ZA
    if (glfwKey >= GLFW_KEY_A && glfwKey <= GLFW_KEY_Z) return static_cast<NovlKeyCode>(static_cast<uint16>(NovlKeyCode::A) + (glfwKey - GLFW_KEY_A));
    
    // 0-9
    if (glfwKey >= GLFW_KEY_0 && glfwKey <= GLFW_KEY_9) return static_cast<NovlKeyCode>(static_cast<uint16>(NovlKeyCode::Num0) + (glfwKey - GLFW_KEY_0));

    switch (glfwKey) {
        // control keys & symbol keys
        case GLFW_KEY_ENTER:         return NovlKeyCode::Enter;
        case GLFW_KEY_ESCAPE:        return NovlKeyCode::Escape;
        case GLFW_KEY_BACKSPACE:     return NovlKeyCode::Backspace;
        case GLFW_KEY_TAB:           return NovlKeyCode::Tab;
        case GLFW_KEY_SPACE:         return NovlKeyCode::Space;
        case GLFW_KEY_MINUS:         return NovlKeyCode::Minus;
        case GLFW_KEY_EQUAL:         return NovlKeyCode::Equal;
        case GLFW_KEY_LEFT_BRACKET:  return NovlKeyCode::LeftBracket;
        case GLFW_KEY_RIGHT_BRACKET: return NovlKeyCode::RightBracket;
        case GLFW_KEY_BACKSLASH:     return NovlKeyCode::Backslash;
        case GLFW_KEY_SEMICOLON:     return NovlKeyCode::Semicolon;
        case GLFW_KEY_APOSTROPHE:    return NovlKeyCode::Apostrophe;
        case GLFW_KEY_GRAVE_ACCENT:  return NovlKeyCode::Grave;
        case GLFW_KEY_COMMA:         return NovlKeyCode::Comma;
        case GLFW_KEY_PERIOD:        return NovlKeyCode::Period;
        case GLFW_KEY_SLASH:         return NovlKeyCode::Slash;
        case GLFW_KEY_CAPS_LOCK:     return NovlKeyCode::CapsLock;

        // F1-F12
        case GLFW_KEY_F1:  return NovlKeyCode::F1;
        case GLFW_KEY_F2:  return NovlKeyCode::F2;
        case GLFW_KEY_F3:  return NovlKeyCode::F3;
        case GLFW_KEY_F4:  return NovlKeyCode::F4;
        case GLFW_KEY_F5:  return NovlKeyCode::F5;
        case GLFW_KEY_F6:  return NovlKeyCode::F6;
        case GLFW_KEY_F7:  return NovlKeyCode::F7;
        case GLFW_KEY_F8:  return NovlKeyCode::F8;
        case GLFW_KEY_F9:  return NovlKeyCode::F9;
        case GLFW_KEY_F10: return NovlKeyCode::F10;
        case GLFW_KEY_F11: return NovlKeyCode::F11;
        case GLFW_KEY_F12: return NovlKeyCode::F12;

        // others
        case GLFW_KEY_PRINT_SCREEN:  return NovlKeyCode::PrintScreen;
        case GLFW_KEY_SCROLL_LOCK:   return NovlKeyCode::ScrollLock;
        case GLFW_KEY_PAUSE:         return NovlKeyCode::Pause;
        case GLFW_KEY_INSERT:        return NovlKeyCode::Insert;
        case GLFW_KEY_HOME:          return NovlKeyCode::Home;
        case GLFW_KEY_PAGE_UP:       return NovlKeyCode::PageUp;
        case GLFW_KEY_DELETE:        return NovlKeyCode::Delete;
        case GLFW_KEY_END:           return NovlKeyCode::End;
        case GLFW_KEY_PAGE_DOWN:     return NovlKeyCode::PageDown;
        case GLFW_KEY_RIGHT:         return NovlKeyCode::RightArrow;
        case GLFW_KEY_LEFT:          return NovlKeyCode::LeftArrow;
        case GLFW_KEY_DOWN:          return NovlKeyCode::DownArrow;
        case GLFW_KEY_UP:            return NovlKeyCode::UpArrow;
        case GLFW_KEY_NUM_LOCK:      return NovlKeyCode::NumLock;

        // Add more key mappings as needed
        default:                     return NovlKeyCode::AnyKey; // Unknown key
    }
}
} // namespace Novl