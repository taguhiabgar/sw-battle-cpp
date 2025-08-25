#include "Features/Swordsman.hpp"
#include <iostream>
namespace sw::feature {

    void Swordsman::spawn() {

    }

    
    void Swordsman::makeMove(Board& board) {
        std::cout << "--- swordsman " << _id << " - make move" << std::endl;
    }

    void Swordsman::receiveDamage(int damage, const Unit* attacker) {

    }
    
    void Swordsman::move(int dx, int dy) {
        
    }

} // namespace sw::feature

