#include "Board.hpp"

namespace sw::core {

    Unit* Board::getUnit(Position position) {
        if (isValidPosition(position)) {
            const uint32_t id = ground[position.x][position.y];
            if (id != InvalidId) {
                return getUnit(id);
            }
        }
        return nullptr;
    }

    Position Board::getTopLeftPosition(Position position, uint32_t radius) {
        Position topLeft {0, 0};
        if (position.x >= radius) {
            topLeft.x = position.x - radius;
        }
        if (position.y >= radius) {
            topLeft.y = position.y - radius;
        }
        return topLeft;
    }

    Position Board::getBottomRightPosition(Position position, uint32_t radius) {
        uint32_t x = std::min(position.x + radius, _width - 1);
        uint32_t y = std::min(position.y + radius, _height - 1);
        return Position{x, y};
    }

    Unit* Board::getAnyNeighbor(Position position, uint32_t fromDistance, uint32_t toDistance) {
        Position topLeft = getTopLeftPosition(position, toDistance);
        Position bottomRight = getBottomRightPosition(position, toDistance);
        Position innerTopLeft = getTopLeftPosition(position, fromDistance);
        Position innerBottomRight = getBottomRightPosition(position, fromDistance);
        assert(isValidPosition(topLeft));
        assert(isValidPosition(bottomRight));
        for (size_t i = topLeft.x; i <= bottomRight.x; ++i) {
            for (size_t j = topLeft.y; j <= bottomRight.y; ++j) {
                if (i >= innerTopLeft.x && i <= innerBottomRight.x && 
                    j >= innerTopLeft.y && j <= innerBottomRight.y) {
                    continue;
                }
                if (ground[i][j] != InvalidId) {
                    return getUnit(ground[i][j]);
                }
            }
        }
        return nullptr;
    }

    std::vector<Unit *> Board::getAllNeighbors(Position position, uint32_t fromDistance, uint32_t toDistance) {
        std::vector<Unit *> allNeighbors;
        Position topLeft = getTopLeftPosition(position, toDistance);
        Position bottomRight = getBottomRightPosition(position, toDistance);
        Position innerTopLeft = getTopLeftPosition(position, fromDistance);
        Position innerBottomRight = getBottomRightPosition(position, fromDistance);
        assert(isValidPosition(topLeft));
        assert(isValidPosition(bottomRight));
        for (size_t i = topLeft.x; i <= bottomRight.x; ++i) {
            for (size_t j = topLeft.y; j <= bottomRight.y; ++j) {
                if (i >= innerTopLeft.x && i <= innerBottomRight.x && 
                    j >= innerTopLeft.y && j <= innerBottomRight.y) {
                    continue;
                }
                if (ground[i][j] != InvalidId) {
                    allNeighbors.push_back(getUnit(ground[i][j]));
                }
            }
        }
        return allNeighbors;
    }

    Unit* Board::getAnyNeighbor(Position position, uint32_t radius) {
        return getAnyNeighbor(position, 0, radius);
    }

    std::vector<Unit *> Board::getAllNeighbors(Position position, uint32_t radius) {
        return getAllNeighbors(position, 0, radius);
    }

    void Board::removeUnit(uint32_t id) {
        auto it = units.find(id);
        if (it != units.end()) {
            units.erase(it);
        }
    }

    void Board::moveUnit(uint32_t id, Position from, Position to) {
        if (!isValidPosition(from) || !isValidPosition(to)) {
            return;
        }
        std::swap(ground[from.x][from.y], ground[to.x][to.y]);
    }

    bool Board::isValidPosition(Position position) {
        return position.x < _width && position.y < _height;
    }

} // namespace sw::core

