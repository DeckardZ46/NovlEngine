/**
 * < Novl Engine > Types.h
 * Author: DeckardZ46
 * Date: 2024/08/30
 * Note: This file includes customized type & containers in Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

#include <memory>
#include <mutex>
#include <vector>
#include <unordered_map>

#include <Core/Containers/CircularQueue.hpp>

/**
 *  For now it's just a wrapper for STL types and containers, maybe replace them with other implementation in the future
 */
namespace Novl {
// types
using n_string = std::string;
using n_lock = std::mutex;
using n_float = float;
using n_floatL = double;

// containers
template <typename T> using n_vector = std::vector<T>;

template <typename k, typename v, typename hash = std::hash<k>> using n_hashmap = std::unordered_map<k, v, hash>;

template <typename T> using n_cqueue = CircularQueue<T>;

template <typename T> using n_cqueue_safe = SafeCircularQueue<T>;

// smart pointers
template <typename T> using n_uptr = std::unique_ptr<T>;

template <typename T> using n_sptr = std::shared_ptr<T>;

template <typename T> using n_wptr = std::weak_ptr<T>;

template <typename T, typename... Args> n_uptr<T> make_unique(Args &&...args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args> n_sptr<T> make_shared(Args &&...args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}
} // namespace Novl