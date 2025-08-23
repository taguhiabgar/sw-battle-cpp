#pragma once

#include "Core/Unit.hpp"
#include "Core/IMovable.hpp"

namespace sw::feature {
    using sw::core::Unit;
    using sw::core::Stats;
    using sw::core::Position;
    using sw::core::IMovable;

    class Hunter : public Unit, public IMovable {
    public:
        Hunter(int id, int health, int agility, int strength, int range, Position position)
        : Unit(id, Stats{.health = health, .agility = agility, .strength = strength, .range = range}, position, true) {}

        void spawn() override;
        void makeMove() override;
        void receiveDamage(int damage) override;
        void move(int dx, int dy) override;
    };

} // namespace sw::feature

