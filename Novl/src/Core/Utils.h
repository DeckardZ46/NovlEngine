/**
 * < Novl Engine > Utils.h
 * Author: DeckardZ46
 * Date: 2024/11/05
 * Note: Misc helper functions for Novl Engine.
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */

#pragma once 
#include <chrono>
#include <sstream>

/**
 * Time related
 */
enum time_type {
    TIME_COMPLETE = 0,
    TIME_NO_DATE
};

std::string nformat_time(const std::chrono::system_clock::time_point& time_point, time_type type);

/**
 * Others
 */

size_t nHashString(std::string str);