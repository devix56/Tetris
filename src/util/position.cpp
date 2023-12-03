#include "position.h"

// Constructors
Position::Position(int row, int column) {
    this->row = row;
    this->column = column;
}

// Methods


// Getters & Setters
int Position::GetRow() { return this->row; }
int Position::GetColumn() { return this->column; }