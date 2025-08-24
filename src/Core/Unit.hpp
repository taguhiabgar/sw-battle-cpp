#pragma once

#include "Core/Stats.hpp"
#include "Core/Position.hpp"

namespace sw::core {

class Unit {
public:
    Unit(int id, const Stats& stats, Position position, bool onBoard)
        : _id(id), _stats(stats), _position(position), _isOnBoard(onBoard), _isAlive(true) { }
    virtual ~Unit() = default;
    
    virtual void spawn() = 0;
    virtual void makeMove() = 0;
    virtual void receiveDamage(int damage, const Unit* attacker) = 0;
    
    inline bool isOnBoard() { return _isOnBoard; }
    inline bool isAlive() { return _isAlive; }
    
protected:
    int _id;
    Stats _stats;
    Position _position;
    bool _isOnBoard;
    bool _isAlive;
};

} // namespace sw::core

