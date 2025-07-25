#pragma once

#include "raylib.h"
#include "gameState.h"

class PauseMenu
{
private:
    bool isPaused = false;

public:
    PauseMenu();
    ~PauseMenu();

    void Draw();

    void TextButton(Vector2 position, int size, const char * text);
};