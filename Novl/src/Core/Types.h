/**
 * < Novl Engine > Types.h
 * Author: DeckardZ46
 * Date: 2024/08/30
 * Note: This file includes customized type & containers in Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <mutex>

/**
 *  For now it's just a wrapper for STL types and containers, maybe replace them with own implementation in the future
 */
namespace Novl{
    using n_string  = std::string;
    using n_vector  = std::vector;
    using n_mutex   = std::mutex;

    /**
     * smart pointer
     */
    template<typename T>
    using n_uptr = std::unique_ptr<T>;

    template<typename T>
    using n_sptr = std::shared_ptr<T>;

    template<typename T>
    using n_wptr = std::weak_ptr<T>;

    template<typename T, typename... Args>
    n_uptr<T> make_unique(Args&&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    n_sptr<T> make_shared(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}