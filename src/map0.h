#pragma once

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include <iostream>

class Map0
{
private:
    Camera2D camera = { 0 };

    Vector2 mousePos = {0};
    Vector2 shipTarget = {0};
    Vector2 shipTargetPos = {0};
    Vector2 shipPos = {0};

public:
    Map0();
    ~Map0();

    void Draw();

    void Update();
};