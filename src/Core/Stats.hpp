#pragma once

#include <cstdint>
#include <optional>

namespace sw::core {

struct Stats {
    std::optional<uint32_t> health;
    std::optional<uint32_t> agility;
    std::optional<uint32_t> power;
    std::optional<uint32_t> spirit;
    std::optional<uint32_t> strength;
    std::optional<uint32_t> range;
};

} // namespace sw::core
