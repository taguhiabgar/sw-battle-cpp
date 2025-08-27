#include "Core/Game.hpp"
#include "Core/Unit.hpp"
#include "Features/Hunter.hpp"
#include "Features/Swordsman.hpp"
#include "IO/Commands/CreateMap.hpp"
#include "IO/Commands/March.hpp"
#include "IO/Commands/SpawnHunter.hpp"
#include "IO/Commands/SpawnSwordsman.hpp"
#include "IO/Events/MapCreated.hpp"
#include "IO/Events/MarchEnded.hpp"
#include "IO/Events/MarchStarted.hpp"
#include "IO/Events/UnitAttacked.hpp"
#include "IO/Events/UnitDied.hpp"
#include "IO/Events/UnitMoved.hpp"
#include "IO/Events/UnitSpawned.hpp"
#include "IO/System/PrintDebug.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace sw::core {

void Game::start()
{
    if (!_board.get()) {
        throw std::runtime_error("Error: Board is null");
    }
    // while (true)
    {
        _moveNumber++;
        for (uint32_t& id : _moveOrder) {
            Unit* unit = _board->getUnit(id);
            if (unit) {
                unit->makeMove(*_board.get());
            }
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
    _board = std::make_unique<Board>(command);
    _eventLog.log(_moveNumber, io::MapCreated{command.width, command.height});
}

void Game::spawnSwordsman(io::SpawnSwordsman& command)
{
    printDebug(std::cout, command);
    spawnUnit<sw::feature::Swordsman>(command);
    _eventLog.log(_moveNumber, io::UnitSpawned{command.unitId, "Swordsman", command.x, command.y});
}

void Game::spawnHunter(io::SpawnHunter& command)
{
    printDebug(std::cout, command);
    spawnUnit<sw::feature::Hunter>(command);
    _eventLog.log(_moveNumber, io::UnitSpawned{command.unitId, "Hunter", command.x, command.y});
}

void Game::march(io::March& command)
{
    printDebug(std::cout, command);
    Unit* unit = _board->getUnit(command.unitId);
    auto pos = _board->getUnitPosition(command.unitId);
    if (!unit || !pos) {
        return;
    }
    if (auto* movable = dynamic_cast<IMovable*>(unit)) {
        movable->move(command.targetX, command.targetY);
        _eventLog.log(_moveNumber, io::MarchStarted{command.unitId, pos->x, pos->y, command.targetX, command.targetY});
    }
}


} // namespace sw::core
