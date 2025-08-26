#pragma once

#include "IO/Commands/CreateMap.hpp"
#include "Unit.hpp"
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cassert>

namespace sw::core {

    using sw::core::Unit;

    class Board
    {
    
    public:
        Board(io::CreateMap command)
            : _width(command.width), _height(command.height), 
            ground(std::vector<std::vector<uint32_t>>(_width, std::vector<uint32_t>(_height, InvalidId))) {}
        ~Board() = default;

        uint32_t storeUnit(std::unique_ptr<Unit> u, Position position) {
            const uint32_t id = u->id();
            if (units.find(id) != units.end())
            {
                std::string message = "Error: Unit ID " + std::to_string(id) + " already exists";
                throw std::runtime_error(message);
            }
            ground[position.x][position.y] = id;
            units[id] = std::move(u);
            return id;
        }

        Unit* getUnit(uint32_t id) {
            if (auto it = units.find(id); it != units.end()) {
                return it->second.get();
            }
            return nullptr;
        }

        Unit* getUnit(Position position);

        Position getTopLeftPosition(Position position, uint32_t radius);

        Position getBottomRightPosition(Position position, uint32_t radius);

        Unit* getAnyNeighbor(Position position, uint32_t fromDistance, uint32_t toDistance);

        std::vector<Unit *> getAllNeighbors(Position position, uint32_t fromDistance, uint32_t toDistance);

        Unit* getAnyNeighbor(Position position, uint32_t radius);

        std::vector<Unit *> getAllNeighbors(Position position, uint32_t radius);

        void removeUnit(uint32_t id);

        void moveUnit(uint32_t id, Position from, Position to);

        bool isValidPosition(Position position);

        static constexpr uint32_t InvalidId {0};

    private:
        uint32_t _width{};
		uint32_t _height{};

        std::vector<std::vector<uint32_t>> ground;
        std::unordered_map<uint32_t, std::unique_ptr<Unit>> units;
    };
    
} // namespace sw::core
