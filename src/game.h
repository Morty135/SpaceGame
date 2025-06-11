#pragma once

#include "raylib.h"
#include "menu.h"
#include "scenes.h"

class Game
{
private:
    Camera2D camera = { 0 };

    typedef enum GameScene {mainMenu = 0, map1} GameScene;

    Menu menu;

    Rectangle Rec;

public:           
    GameScene scene = mainMenu;

    Game();
    ~Game();

    void Update();

    void Draw();
};
