#pragma once

#include <fstream>

enum class Scenes 
{
    MAIN_MENU,
    MAP0,
    SETTINGS,
    EXIT //stops the main while loop
};

extern Scenes currentScene;



class GameState
{
    public:
        void SaveGame();

        void LoadGame();
};