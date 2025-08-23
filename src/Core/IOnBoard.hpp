#pragma once

#include "Core/Position.hpp"

namespace sw::core
{

    struct IOnBoard {
    public:
        virtual void putOnBoard(Position position) = 0;
        virtual ~IOnBoard() = default;
    protected:
        Position positionOnBoard;
    };

} // namespace sw::core
