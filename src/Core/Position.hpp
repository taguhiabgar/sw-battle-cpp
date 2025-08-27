#pragma once

#include <cstdint>

namespace sw::core
{

    struct Position {
        uint32_t x;
        uint32_t y;

        bool operator==(const Position& other) const = default;
    };

} // namespace sw::core
