#pragma once

#include "Core/Position.hpp"
#include <optional>

namespace sw::core
{

    struct IMovable {
    public:
        virtual void move(int dx, int dy) = 0;
        virtual ~IMovable() = default;
    protected:
        std::optional<Position> objective;
    };

} // namespace sw::core
