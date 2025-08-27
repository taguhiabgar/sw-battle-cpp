#pragma once

#include "Core/Unit.hpp"
#include "Core/IMovable.hpp"
#include "IO/Commands/SpawnSwordsman.hpp"
#include <cstdint>

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
                true) 
            {

            }

        void spawn() override;
        bool makeMove(uint32_t moveNumber, Board& board) override;
        void receiveDamage(uint32_t damage, const Unit* attacker, uint32_t moveNumber) override;

        static constexpr uint32_t Radius = 1;

    };

} // namespace sw::feature

