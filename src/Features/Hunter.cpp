#include "Features/Hunter.hpp"
#include <iostream>
namespace sw::feature {

    void Hunter::spawn() {

    }

    
    void Hunter::makeMove(Board& board) {
        std::cout << "--- hunter " << _id << " - make move" << std::endl;
    }

    void Hunter::receiveDamage(int damage, const Unit* attacker) {

    }

    void Hunter::move(int dx, int dy) {
        
    }

} // namespace sw::feature

