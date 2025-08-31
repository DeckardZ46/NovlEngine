/**
 * < Novl Engine > Event.h
 * Author: DeckardZ46
 * Date: 2024/11/16
 * Note: Event system for Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once 

namespace Novl{
// An event system for Novl Engine
class Event{
public: 
    Event() = default;
    virtual ~Event() = default;

    // event type
    enum class Type{
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    virtual Type getEventType() const = 0;
    virtual const char* getName() const = 0;
    virtual int getCategoryFlags() const = 0;
    virtual n_string toString() const { return getName(); }

    inline bool isInCategory(int category){
        return getCategoryFlags() & category;
    }

    bool handled = false; // whether the event has been handled
};
} // namespace Novl