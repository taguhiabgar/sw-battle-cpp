#pragma once

#include "IO/Commands/CreateMap.hpp"

namespace sw::core {

    class Board
    {
    
    public:
        Board()
            : _width(0), _height(0) {}
        Board(io::CreateMap command)
            : _width(command.width), _height(command.height) {}
        ~Board() = default;

    private:
        uint32_t _width{};
		uint32_t _height{};
    };
    
} // namespace sw::core
