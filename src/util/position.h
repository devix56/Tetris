#pragma once

class Position {

private:
    int row;
    int column;

public:
    Position(int row, int column);

    int GetRow();
    int GetColumn();
};