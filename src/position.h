//
// Created by dalacroi on 21.11.2023.
//
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