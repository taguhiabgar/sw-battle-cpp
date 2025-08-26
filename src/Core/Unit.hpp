#pragma once

#include "Core/Stats.hpp"
#include "Core/Position.hpp"
#include <cstdint>

namespace sw::core {

class Board;

class Unit {
public:
    Unit(uint32_t id, const Stats& stats, Position position, bool onBoard)
        : _id(id), _stats(stats), _position(position), _isOnBoard(onBoard), _isAlive(true) { }
    virtual ~Unit() = default;
    
    virtual void spawn() = 0;
    virtual void makeMove(Board& board) = 0;
    virtual void receiveDamage(uint32_t damage, const Unit* attacker) = 0;
    
    inline bool isOnBoard() const { return _isOnBoard; }
    inline bool isAlive() const { return _isAlive; }
    inline uint32_t id() const { return _id; }
    inline const Stats& stats() const { return _stats; }
    inline const Position& position() const { return _position; }
    
protected:
    uint32_t _id;
    Stats _stats;
    Position _position;
    bool _isOnBoard;
    bool _isAlive;
};

} // namespace sw::core

