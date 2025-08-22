#pragma once

#include <optional>

namespace sw::core {

struct Stats {
    std::optional<int> health;
    std::optional<int> agility;
    std::optional<int> power;
    std::optional<int> spirit;
    std::optional<int> strength;
    std::optional<int> range;
};

} // namespace sw::core
