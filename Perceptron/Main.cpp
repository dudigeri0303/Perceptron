#include<iostream>
#include "raylib.h"

int main(void)
{
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
    const int windowWidth = 1200;
    const int windowHeight = 800;
    InitWindow(windowWidth, windowHeight, "Perceptron");

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();

    _CrtDumpMemoryLeaks();
    return 0;
}