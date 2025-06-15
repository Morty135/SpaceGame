#pragma once

#include "raylib.h"
#include <iostream>

class Map0
{
private:
    Camera2D camera = { 0 };

    Rectangle Rec;

public:
    Map0();
    ~Map0();

    void Draw();

    void Update();
};