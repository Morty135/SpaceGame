#include "map0.h"

Map0::Map0()
{
    camera.target = (Vector2){ 0.0f, 0.0f };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;

    background = LoadTexture("resources/map0/background.png");
    background.width = GetScreenWidth()*2;
    background.height = GetScreenHeight()*2;

    gate1 = LoadTexture("resources/map0/Gate.png");
    gate1.width = gate1.width*4;
    gate1.height = gate1.height*4;
}

void Map0::Update()
{
    mousePos = GetScreenToWorld2D(GetMousePosition(), camera);

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        shipTargetPos = mousePos;
    }
    shipPos = Vector2MoveTowards(shipPos, shipTargetPos, 5);

    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        float scale = 0.05f*wheel;
        camera.zoom = Clamp(expf(logf(camera.zoom)+scale), 1.0f, 7.0f);
    }
    camera.target = shipPos;
}

void Map0::Draw()
{
    ClearBackground({23,9,12,255});

    BeginMode2D(camera);

        DrawTexture(background, shipPos.x * 0.5f , shipPos.y * 0.5f, WHITE);

        DrawTexture(gate1,1920 , 1080, WHITE);

        DrawRectangleV(shipPos, {40, 40 }, LIME);

    EndMode2D();
}

Map0::~Map0() 
{
    UnloadTexture(gate1);
    UnloadTexture(background);
}