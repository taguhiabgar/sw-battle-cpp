#include "Core/Game.hpp"
#include "IO/Commands/CreateMap.hpp"
#include "IO/Commands/March.hpp"
#include "IO/Commands/SpawnHunter.hpp"
#include "IO/Commands/SpawnSwordsman.hpp"
#include "IO/System/PrintDebug.hpp"
#include <iostream>

namespace sw::core {

void Game::start()
{
    
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
    printDebug(std::cout, command);
}

void Game::spawnHunter(io::SpawnHunter& command)
{
    printDebug(std::cout, command);
}

void Game::march(io::March& command)
{
    printDebug(std::cout, command);
}

void Game::spawnUnit()
{
    
}

} // namespace sw::core
