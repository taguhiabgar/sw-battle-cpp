#pragma once

#include "Core/Unit.hpp"
#include "Core/IMovable.hpp"

namespace sw::feature {

    using sw::core::Unit;
    using sw::core::Stats;
    using sw::core::Position;
    using sw::core::IMovable;

    class Swordsman : public Unit, public IMovable {
        public:
        Swordsman(int id, int health, int strength, Position position)
            : Unit(id, Stats{ .health = health, .strength = strength }, position, true) {}

        void spawn() override;
        void makeMove() override;
        void receiveDamage(int damage, const Unit* attacker) override;
        void move(int dx, int dy) override;
    };

} // namespace sw::feature

