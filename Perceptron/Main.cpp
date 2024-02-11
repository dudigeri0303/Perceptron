#include <iostream>
#include "raylib.h"
#include "Gui.h"

int main(void)
{
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
    Gui* gui = new Gui;
    const int windowWidth = 1200;
    const int windowHeight = 800;
    InitWindow(windowWidth, windowHeight, "Perceptron");

    while (!WindowShouldClose())
    {
        gui->HandleGuiElements();
        gui->Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        gui->Draw();
        EndDrawing();
    }
    CloseWindow();
    delete gui;

    _CrtDumpMemoryLeaks();
    return 0;
}