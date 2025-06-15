#pragma once

#include "raylib.h"
#include "menu.h"
#include "scenes.h"
#include "map0.h"

class Game
{
private:
    Menu menu;
    Map0 map0;

public:           
    Game();
    ~Game();

    void Update();

    void Draw();
};
