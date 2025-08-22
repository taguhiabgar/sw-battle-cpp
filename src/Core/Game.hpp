#pragma once

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

        void spawnUnit();
        void createMap(io::CreateMap& command);
        void spawnSwordsman(io::SpawnSwordsman& command);
        void spawnHunter(io::SpawnHunter& command);
        void march(io::March& command);

    private:
        // ...
    };

} // namespace sw::core
