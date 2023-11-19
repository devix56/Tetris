//
// Created by dan10 on 19.11.2023.
//
#include "grid.h"
#include <iostream>

Grid::Grid(const int ROWS, const int COLUMNS, const int CELLSIZE) {
    rows = ROWS;
    columns = COLUMNS;
    cellSize = CELLSIZE;

    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    grid = new int*[rows];

    for(int y = 0; y < rows; y++)
    {
        grid[y] = new int[columns];

        for(int x = 0; x < columns; x++)
        {
            grid[y][x] = 0;
        }
    }
}

void Grid::Print()
{

    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
        {
            std::cout << grid[y][x] << " ";
        }

        std::cout << std::endl;
    }
}

void Grid::Draw()
{

    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
        {
            int cellValue = grid[y][x];

            int cellX = x * cellSize + 1;
            int cellY = y * cellSize + 1;
            DrawRectangle(cellX, cellY, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

std::vector<Color> Grid::GetCellColors()
{
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::SetCellValue(const int X, const int Y, const int CELLVALUE) {
    grid[Y][X] = CELLVALUE;
}