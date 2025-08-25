#include "Core/Game.hpp"
#include "Core/Unit.hpp"
#include "Features/Hunter.hpp"
#include "Features/Swordsman.hpp"
#include "IO/Commands/CreateMap.hpp"
#include "IO/Commands/March.hpp"
#include "IO/Commands/SpawnHunter.hpp"
#include "IO/Commands/SpawnSwordsman.hpp"
#include "IO/System/PrintDebug.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace sw::core {

void Game::start()
{
    // while (true)
    {
        for (auto& unit : units) {
            unit->makeMove();
        }
    }
    
}

void Game::update()
{
    
}

void Game::end()
{
    
}
void Game::createMap(io::CreateMap& command)
{
    printDebug(std::cout, command);
}

void Game::spawnSwordsman(io::SpawnSwordsman& command)
{
    spawnUnit<sw::feature::Swordsman>(command);
    printDebug(std::cout, command);
}

void Game::spawnHunter(io::SpawnHunter& command)
{
    spawnUnit<sw::feature::Hunter>(command);
    printDebug(std::cout, command);
}

void Game::march(io::March& command)
{
    printDebug(std::cout, command);
}


} // namespace sw::core
