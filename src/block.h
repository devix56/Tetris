//
// Created by dalacroi on 21.11.2023.
//
#pragma once

#include <vector>
#include <map>

#include "position.h"
#include "colors.h"

class Block {

protected:
    int id;
    std::map<int, std::vector<Position>> cells;
    int cellSize;
    int rotationState; // Goes from 0-3
    std::vector<Color> colors;

    int rowOffset; // Row offset inside the grid
    int columnOffset; // Column offset inside the grid

public:

    // Constructors
    Block();

    // Methods
    void Draw(int offsetX, int offsetY);                                // Draws the block inside the grid
    void Move(int rows, int columns);           // Moves the block by a amount of rows and columns

    // Getters & Setters
    int GetId() { return this->id; }
    std::vector<Position> GetCellPositions();

    void Rotate();

    void UndoRotation();
};