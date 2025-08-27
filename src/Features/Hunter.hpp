#pragma once

#include "IO/Commands/SpawnHunter.hpp"
#include "Core/Unit.hpp"
#include "Core/IMovable.hpp"
#include <cstdint>

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
                true)
            {

            }

        void spawn(/*io::SpawnHunter& command*/) override;
        bool makeMove(uint32_t moveNumber, Board& board) override;
        void receiveDamage(uint32_t damage, const Unit* attacker, uint32_t moveNumber) override;

        static constexpr uint32_t Radius = 1;
    };

} // namespace sw::feature

