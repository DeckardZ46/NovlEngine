/**
 * < Novl Engine > MouseInput.h
 * Author: DeckardZ46
 * Date: 2025/09/01
 * Note: Mouse Input Definitions of Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

namespace Novl {
enum class NovlMouseButton : uint8 {
    AnyMouseButton  = 0,
    Left            = 1,
    Right           = 2,
    Middle          = 3,
    ButtonX1        = 4,
    ButtonX2        = 5
};

enum class NovlMouseAction : uint8 {
    None        = 0,
    Press       = 1,
    Release     = 2,
    Repeat      = 3,
    Move        = 4,
    Scroll      = 5
};
} // namespace Novl