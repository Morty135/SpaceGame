#include "pauseMenu.h"

PauseMenu::PauseMenu()
{

}

void PauseMenu::ReturnToMainMenu()
{
    currentScene = Scenes::MAIN_MENU;
}

void PauseMenu::CloseMenu()
{
    isPaused = false;
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
        DrawRectangle(GetScreenWidth()*0.35f,0,GetScreenWidth()*0.3f, GetScreenHeight(), BLACK);
        DrawText("Quick Menu", GetScreenWidth()*0.5f - MeasureText("Quick Menu", 60)*0.5f, 30, 60, GRAY);
        TextButton({GetScreenWidth()*0.5f,150}, 50, "Play", &PauseMenu::CloseMenu);
        TextButton({GetScreenWidth()*0.5f,250}, 50, "Save");
        TextButton({GetScreenWidth()*0.5f,350}, 50, "Load");
        TextButton({GetScreenWidth()*0.5f,450}, 50, "Menu", &PauseMenu::ReturnToMainMenu);

    }
}

void PauseMenu::TextButton(Vector2 position, int size, const char * text, void (PauseMenu::*func)())
{
    int width = MeasureText(text, size);
    Rectangle Rec = {position.x - width*0.5f, position.y, width, size};
    //DrawRectangleRec(Rec, {RAYWHITE});

    if(CheckCollisionPointRec(GetMousePosition(), Rec))
    {
        DrawText(text, position.x - width*0.5f, position.y, size, GRAY);
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            isPaused = false;
            (this->*func)();
        }
    }
    else
    {
        DrawText(text, position.x - width*0.5f, position.y, size, LIGHTGRAY);
    }

}

PauseMenu::~PauseMenu()
{

}