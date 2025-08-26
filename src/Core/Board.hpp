#pragma once

#include "IO/Commands/CreateMap.hpp"

#include <unordered_map>
#include <memory>
#include <cstdint>

namespace sw::core {

    using sw::core::Unit;

    class Board
    {
    
    public:
        Board()
            : _width(0), _height(0) {}
        Board(io::CreateMap command)
            : _width(command.width), _height(command.height) {}
        ~Board() = default;

        uint32_t storeUnit(std::unique_ptr<Unit> u) {
            uint32_t id = u->id();
            while (units.find(id) != units.end())
            {
                id++;
            }
            units[id] = std::move(u);
            return id;
        }

        Unit* getUnit(uint32_t id) {
            if (auto it = units.find(id); it != units.end()) {
                return it->second.get();
            }
            return nullptr;
        }

    private:
        uint32_t _width{};
		uint32_t _height{};

        std::unordered_map<uint32_t, std::unique_ptr<Unit>> units;

    };
    
} // namespace sw::core
