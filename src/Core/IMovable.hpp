#pragma once

#include "Core/Position.hpp"
#include <optional>
#include <cstdint>

namespace sw::core
{

    struct IMovable {
    public:
        virtual void move(uint32_t dx, uint32_t dy) = 0;
        virtual ~IMovable() = default;
    protected:
        std::optional<Position> objective;
    };

} // namespace sw::core
