#include "Features/Hunter.hpp"
#include "Core/Board.hpp"
#include <iostream>

namespace sw::feature {

    void Hunter::spawn() {

    }

    
    void Hunter::makeMove(Board& board) {
        std::cout << "--- hunter " << _id << " - make move" << std::endl;
    }

    void Hunter::receiveDamage(uint32_t damage, const Unit* attacker) {

    }

    void Hunter::move(uint32_t dx, uint32_t dy) {
        
    }

} // namespace sw::feature

