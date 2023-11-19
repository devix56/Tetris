//
// Created by dan10 on 19.11.2023.
//
#pragma once

#include <vector>
#include "raylib.h"

class Grid {

private:
    int rows;
    int columns;
    int cellSize;

    int** grid;

    std::vector<Color> colors;

public:
    Grid() = delete;
    Grid(int ROWS, int COLUMNS, int CELLSIZE);
    ~Grid() = default;

    void Initialize();
    void Print();
    void Draw();

    std::vector<Color> GetCellColors();
    void SetCellValue(const int X, const int Y, const int CELLVALUE);

};

