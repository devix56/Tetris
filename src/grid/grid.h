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

    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int rowsDown);

public:
    Grid() = default;
    Grid(int ROWS, int COLUMNS, int CELLSIZE);
    ~Grid() = default;

    void Initialize();
    void Print();
    void Draw();
    int ClearFullRows();

    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);

    void SetCellValue(const int X, const int Y, const int CELLVALUE);

};

