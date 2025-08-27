#include "Features/Swordsman.hpp"
#include "Core/Board.hpp"
#include "IO/Events/UnitAttacked.hpp"
#include "IO/Events/UnitDied.hpp"
#include "IO/Events/UnitMoved.hpp"
#include "IO/Events/UnitSpawned.hpp"
#include <iostream>

namespace sw::feature {

    void Swordsman::spawn() {

    }

    // - Сокрушающий удар: Бьет одного случайного юнита в соседней клетке, нанося ему Strength единиц урона.
    // - Если некого бить, перемещается.
    bool Swordsman::makeMove(uint32_t moveNumber, Board& board, EventLog& eventLog) {
        std::optional<Position> position = board.getUnitPosition(_id);
        assert(position.has_value());
        if (Unit* enemy = board.getAnyNeighbor(position.value(), Radius)) {
            assert(_stats.strength.has_value());
            enemy->receiveDamage(_stats.strength.value(), this);
            eventLog.log(moveNumber, io::UnitAttacked{_id, enemy->id(), _stats.strength.value(), enemy->stats().health.value()});
            if (!enemy->isAlive()){
                eventLog.log(moveNumber, io::UnitDied{enemy->id()});
            }
            return true;
        } else if (objective.has_value()) {
            if (position.value() == objective.value()) {
                // objective achieved
                return false;
            }
            Position next = nextPositionTowardTarget(position.value(), objective.value());
            if (board.isValidPosition(next)) {
                board.moveUnit(_id, position.value(), next);
                eventLog.log(moveNumber, io::UnitMoved{_id, next.x, next.y});
                return true;
            }
        }
        // can't make a move
        return false;
    }

    void Swordsman::receiveDamage(uint32_t damage, const Unit* attacker) {
        assert(_stats.health.has_value());
        if (damage > _stats.health.value()) {
            *_stats.health = 0;
            _isAlive = false;
        } else {
            *_stats.health -= damage;
        }
    }
    
} // namespace sw::feature

