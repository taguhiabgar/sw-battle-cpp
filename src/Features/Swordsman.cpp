#include "Features/Swordsman.hpp"
#include "Core/Board.hpp"
#include <iostream>

namespace sw::feature {

    void Swordsman::spawn() {

    }

    
    void Swordsman::makeMove(Board& board) {
        std::cout << "--- swordsman " << _id << " - make move" << std::endl;
    }

    void Swordsman::receiveDamage(uint32_t damage, const Unit* attacker) {

    }
    
    void Swordsman::move(uint32_t dx, uint32_t dy) {
        
    }

} // namespace sw::feature

