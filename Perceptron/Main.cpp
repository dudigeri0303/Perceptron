#include <iostream>
#include "raylib.h"
#include "Gui.h"

int main(void){
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
    const int windowWidth = 800;
    const int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Perceptron");
    Gui* gui = new Gui;

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