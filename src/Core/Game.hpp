#pragma once

#include "Unit.hpp"
#include "Board.hpp"
#include <vector>
#include <memory>

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
        void update();
        void end();

        template<typename UnitType, typename CommandType>
        void spawnUnit(const CommandType& command)
        {
            std::unique_ptr<Unit> unit = std::make_unique<UnitType>(command);
            _units.push_back(std::move(unit));
            // log UNIT_SPAWNED here - notify all observers?
        }
        
        void createMap(io::CreateMap& command);

        void march(io::March& command);

        void spawnSwordsman(io::SpawnSwordsman& command);

        void spawnHunter(io::SpawnHunter& command);

    private:
        std::vector<std::unique_ptr<Unit>> _units{};
        Board _board{};
    };

} // namespace sw::core
