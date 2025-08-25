#pragma once

#include "IO/Commands/SpawnHunter.hpp"
#include "Core/Unit.hpp"
#include "Core/IMovable.hpp"

namespace sw::feature {
    using sw::core::Unit;
    using sw::core::Stats;
    using sw::core::Board;
    using sw::core::Position;
    using sw::core::IMovable;

    class Hunter : public Unit, public IMovable {
    public:
        Hunter(const sw::io::SpawnHunter& command) : 
            Unit(
                command.unitId, 
                Stats{.health = command.hp, .agility = command.agility, .strength = command.strength, .range = command.range}, 
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

