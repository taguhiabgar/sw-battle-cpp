#pragma once

#include "Core/Position.hpp"
#include <optional>
#include <cstdint>

namespace sw::core
{

    struct IMovable {
    public:
        virtual void startMarch(uint32_t dx, uint32_t dy) {
            Position newPos {dx, dy};
            objective = newPos;
        }

        virtual ~IMovable() = default;

    protected:
        virtual Position nextPositionTowardTarget(Position current, Position target) {
            int dx = (target.x > current.x) - (target.x < current.x); // -1, 0, or 1
            int dy = (target.y > current.y) - (target.y < current.y);

            Position next{current.x + dx, current.y + dy};
            return next;
        }

        std::optional<Position> objective;
    };

} // namespace sw::core
