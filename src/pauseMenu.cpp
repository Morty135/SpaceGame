#include "pauseMenu.h"

PauseMenu::PauseMenu()
{

}

void PauseMenu::Draw()
{
    if(IsKeyPressed(KEY_ESCAPE))
    {
        if (isPaused == true)
        {
            isPaused = false;
        }
        else if (isPaused == false)
        {
            isPaused = true;
        }
    }
    if(isPaused == true)
    {
        DrawRectangle(GetScreenWidth()*0.33f,0,GetScreenWidth()*0.33f, GetScreenHeight(), BLACK);
        TextButton({0,0}, 10, "Hello");

    }
}

void PauseMenu::TextButton(Vector2 position, int size, const char * text)
{
    int width = MeasureText(text, size);
    DrawRectangle(position.x, position.y, width, size, RAYWHITE);
    DrawText(text, position.x, position.y, size, GRAY);
}

PauseMenu::~PauseMenu()
{

}