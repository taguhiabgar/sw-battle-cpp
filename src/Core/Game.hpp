#pragma once

#include "Unit.hpp"
#include "Board.hpp"
#include "IO/System/EventLog.hpp"
#include <vector>
#include <memory>
#include <cstdint>

namespace sw::io {
    class CreateMap;
    class March;
    class SpawnHunter;
    class SpawnSwordsman;
} // namespace sw::io

namespace sw::core
{
    class Game
    {
    public:
        Game() = default;
        ~Game() = default;

        void start();

        template<typename UnitType, typename CommandType>
        void spawnUnit(const CommandType& command)
        {
            std::unique_ptr<Unit> unit = std::make_unique<UnitType>(command);
            Position position { command.x, command.y };
            uint32_t id = _board->storeUnit(std::move(unit), position);
            _moveOrder.push_back(id);
            // log UNIT_SPAWNED here - notify all observers?
        }
        
        void createMap(io::CreateMap& command);

        void march(io::March& command);

        void spawnSwordsman(io::SpawnSwordsman& command);

        void spawnHunter(io::SpawnHunter& command);

    private:
        std::vector<uint32_t> _moveOrder{};
        std::unique_ptr<Board> _board;
        EventLog _eventLog;
        uint64_t _moveNumber {0};
    };

} // namespace sw::core
