#pragma once

namespace sw::core
{
    class Game
    {
    public:
        Game();
        ~Game();

        void start();
        void update();
        void end();

        void createMap();
        void spawnUnit();
        void march();

    private:
        // ...
    };

} // namespace sw::core
