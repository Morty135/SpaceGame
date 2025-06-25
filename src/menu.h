#pragma once

#include "raylib.h"
#include "gameState.h"

class Menu
{
private:
    Texture2D background;
    Sound clickFx;

    Rectangle playRec;
    Rectangle settingsRec;
    Rectangle exitRec;

    int buttonHeight = 100;

public:
    Menu();
    ~Menu();

    void Draw();

    void Button(Rectangle buttonRec, const char * text);
};