#pragma once

#include "Core/Stats.hpp"
#include "Core/Position.hpp"
#include "Core/IObservable.hpp"
#include "IO/System/EventLog.hpp"
#include <cstdint>

namespace sw::core {

class Board;

class Unit : public IObservable {
public:
    Unit(uint32_t id, const Stats& stats, bool onBoard)
        : _id(id), _stats(stats), _isOnBoard(onBoard), _isAlive(true) { }
    virtual ~Unit() = default;
    
    virtual void spawn() = 0;
    virtual bool makeMove(uint32_t moveNumber, Board& board) = 0; // true - did move, false - can't move
    virtual void receiveDamage(uint32_t damage, const Unit* attacker, uint32_t moveNumber) = 0;
    
    inline bool isOnBoard() const { return _isOnBoard; }
    inline bool isAlive() const { return _isAlive; }
    inline uint32_t id() const { return _id; }
    inline const Stats& stats() const { return _stats; }
    
protected:
    uint32_t _id;
    Stats _stats;
    bool _isOnBoard;
    bool _isAlive;
};

} // namespace sw::core

