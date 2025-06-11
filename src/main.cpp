#include "game.h"
#include <iostream>

int main(void)
{
    InitWindow(1920, 1080, "Space Game");
    InitAudioDevice();
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    Game game = Game();

    while (!WindowShouldClose() && currentScene != Scenes::EXIT)
    {
        //maybe make it time independent later
        game.Update();
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.Draw();
        EndDrawing();
    }

    return 0;
}