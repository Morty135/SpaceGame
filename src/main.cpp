#include "game.h"

int main(void)
{
    InitWindow(1920, 1080, "Space Game");
    InitAudioDevice();
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
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