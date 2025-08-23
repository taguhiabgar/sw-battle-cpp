#pragma once

#include "Core/Position.hpp"

namespace sw::core
{

    struct IMovable {
    public:
        virtual void move(int dx, int dy) = 0;
        virtual ~IMovable() = default;
    protected:
        Position objective;
    };

} // namespace sw::core
