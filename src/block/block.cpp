#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();

    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();

    for(Position item : tiles) {
        int x = item.GetColumn() * cellSize + offsetX;
        int y = item.GetRow() * cellSize + offsetY;
        int width = cellSize - 1;
        int height = cellSize - 1;

        DrawRectangle(x, y, width, height, colors[id]);
    }

}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::Rotate()
{
    rotationState++;

    if(rotationState == (int) cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;

    if(rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for(Position item : tiles) {
        Position newPos = Position(item.GetRow() + rowOffset, item.GetColumn() + columnOffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}