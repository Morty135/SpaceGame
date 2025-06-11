#include "game.h"

Game::Game()
{
    camera.target = (Vector2){ 0.0f, 0.0f };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Rec.height = 40;
    Rec.width = 40;
    Rec.x = 0;
    Rec.y = 100;
}



void Game::Update()
{
    Rec.x += 1; 

    switch (currentScene)
    {
        case Scenes::MAIN_MENU:
        {
           // menu.ChangeScene(scene);
        } break;
        case Scenes::MAP0:
        {

        } break;
    }
}



void Game::Draw()
{
    switch (currentScene)
    {
    case Scenes::MAIN_MENU:
        menu.Draw();
    break;
    case Scenes::MAP0:
    BeginMode2D(camera);
        DrawRectangleRec(Rec, RED);
    EndMode2D();
    break;
    }
}



Game::~Game()
{
    CloseWindow();
    CloseAudioDevice();
}