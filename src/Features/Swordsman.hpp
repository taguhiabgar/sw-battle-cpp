#pragma once

#include "Core/Unit.hpp"
#include "Core/IMovable.hpp"
#include "IO/Commands/SpawnSwordsman.hpp"

namespace sw::feature {

    using sw::core::Unit;
    using sw::core::Stats;
    using sw::core::Board;
    using sw::core::Position;
    using sw::core::IMovable;

    class Swordsman : public Unit, public IMovable {
        public:
        Swordsman(const sw::io::SpawnSwordsman& command)
            : Unit(
                command.unitId, 
                Stats{ .health = command.hp, .strength = command.strength}, 
                Position{command.x, command.y},
                true) 
            {

            }

        void spawn() override;
        void makeMove(Board& board) override;
        void receiveDamage(int damage, const Unit* attacker) override;
        void move(int dx, int dy) override;
    };

} // namespace sw::feature

