//
// Created by dan10 on 19.11.2023.
//
#include "grid.h"
#include "colors.h"
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

            int cellX = x * cellSize + 10;
            int cellY = y * cellSize + 10;
            DrawRectangle(cellX, cellY, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

int Grid::ClearFullRows()
{
    int completedRows = 0;

    for(int y = rows-1; y >= 0; y--)
    {
        if(IsRowFull(y))
        {
            ClearRow(y);
            completedRows++;
        }
        else if(completedRows > 0) {
            MoveRowDown(y, completedRows);
        }
    }

    return completedRows;
}

bool Grid::IsCellOutside(int row, int column)
{
    bool insideRows = row >= 0 && row < rows;
    bool insideColumns = column >= 0 && column < columns;

    if(insideRows && insideColumns) {
        return false;
    }

    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0) {
        return true;
    }

    return false;
}

bool Grid::IsRowFull(int row)
{
    for(int x = 0; x < columns; x++)
    {
        if(grid[row][x] == 0)
        {
            return false;
        }
    }

    return true;
}

void Grid::ClearRow(int row)
{
    for(int x = 0; x < columns; x++)
    {
        grid[row][x] = 0;
    }
}

void Grid::MoveRowDown(int row, int rowsDown)
{
    for(int x = 0; x < columns; x++)
    {
        grid[row + rowsDown][x] = grid[row][x];
        grid[row][x] = 0;
    }
}

void Grid::SetCellValue(const int X, const int Y, const int CELLVALUE) {
    grid[Y][X] = CELLVALUE;
}