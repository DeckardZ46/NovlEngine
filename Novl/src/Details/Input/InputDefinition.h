/**
 * < Novl Engine > InputDefinition.h
 * Author: DeckardZ46
 * Date: 2025/08/31
 * Note: Input Definitions of Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

namespace Novl {
enum class InputCategory : uint16 {
    KeyboardInput       = 1 << 0,
    MouseButtonInput    = 1 << 1,
    MouseInput          = 1 << 2,
    WindowInput         = 1 << 3
};

class NovlInput {
    
};
} // namespace Novl