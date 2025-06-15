#include "map0.h"

Map0::Map0()
{
    camera.target = (Vector2){ 0.0f, 0.0f };
    //camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Rec.height = 40;
    Rec.width = 40;
}

void Map0::Update()
{
    Vector2 mousePos = GetWorldToScreen2D(GetMousePosition(),camera);
    Rec.x = mousePos.x;
    Rec.y = mousePos.y;

    DrawRectangle(10,10,780,50,RAYWHITE);
    DrawText(std::to_string(GetMousePosition().x).c_str(), 10, 10, 50, MAGENTA);
    DrawText(std::to_string(GetMousePosition().y).c_str(), 400, 10, 50, MAGENTA);

    DrawRectangle(10,70,780,50,RAYWHITE);
    DrawText(std::to_string(Rec.x).c_str(), 10, 70, 50, MAGENTA);
    DrawText(std::to_string(Rec.y).c_str(), 400, 70, 50, MAGENTA);
}

void Map0::Draw()
{
    BeginMode2D(camera);
        DrawRectangleRec(Rec, RED);
    EndMode2D();
}

Map0::~Map0() 
{

}