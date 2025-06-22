#include "map0.h"

Map0::Map0()
{
    camera.target = (Vector2){ 0.0f, 0.0f };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
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
    DrawRectangle(0,0,GetScreenWidth(), GetScreenHeight(), DARKPURPLE);
    BeginMode2D(camera);
        rlPushMatrix();
            rlTranslatef(0, 25*50, 0);
            rlRotatef(90, 1, 0, 0);
            DrawGrid(100, 50);
        rlPopMatrix();

        DrawRectangleV(shipPos, {40, 40 }, LIME);
    EndMode2D();
}

Map0::~Map0() 
{

}