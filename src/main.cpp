//
// Created by dan10 on 19.11.2023.
//
#include "raylib.h"
#include "grid.h"

/*
 * Grid Constants
 */
const int ROWS = 20;
const int COLUMNS = 10;
const int CELLSIZE = 30;

/**
 * MAIN
 */
int main()
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid(ROWS, COLUMNS, CELLSIZE);
    grid.SetCellValue(0, 0, 1);
    grid.SetCellValue(5, 3, 4);
    grid.SetCellValue(8, 17, 7);
    grid.Print();

    // Game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(DARKBLUE);
            grid.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}