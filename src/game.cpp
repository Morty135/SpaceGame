#include "game.h"

Game::Game()
{

}



void Game::Update()
{
    switch (currentScene)
    {
        case Scenes::MAIN_MENU:
        {

        } break;
        case Scenes::MAP0:
        {
            map0.Update();
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
        map0.Draw();
    break;
    }
}



Game::~Game()
{
    CloseWindow();
    CloseAudioDevice();
}