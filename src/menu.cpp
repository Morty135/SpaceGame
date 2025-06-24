#include "menu.h"


Menu::Menu()
{
    background = LoadTexture("resources/menu/Background1.png");
    clickFx = LoadSound("resources/menu/button-202966.mp3");

    playRec.height = buttonHeight + 10;
    playRec.width = 210;
    playRec.x = 190;
    playRec.y = GetScreenHeight()*0.3f - buttonHeight*0.5;

    settingsRec.height = buttonHeight + 10;
    settingsRec.width = 210;
    settingsRec.x = 190;
    settingsRec.y = GetScreenHeight()*0.5f - buttonHeight*0.5;

    exitRec.height = buttonHeight + 10;
    exitRec.width = 210;
    exitRec.x = 190;
    exitRec.y = GetScreenHeight()*0.7f - buttonHeight*0.5;
}



void Menu::Draw()
{
    DrawTexture(background, 0,0, WHITE);
    Button(playRec, "Play");
    Button(settingsRec, "Settings");
    Button(exitRec, "Exit");
}



void Menu::Button(Rectangle buttonRec, const char * text)
{
    if(CheckCollisionPointRec(GetMousePosition(), buttonRec))
    {
        DrawText(text, buttonRec.x, buttonRec.y, buttonHeight +5, GRAY);
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            PlaySound(clickFx);
            if (text == "Play")
            {
                currentScene = Scenes::MAP0;
            }
            if (text == "Exit")
            {
                currentScene = Scenes::EXIT;
            }
        }
    }
    else
    {
        DrawText(text, buttonRec.x, buttonRec.y, buttonHeight, LIGHTGRAY);
    }
}



Menu::~Menu()
{
    UnloadTexture(background);
    UnloadSound(clickFx);
}