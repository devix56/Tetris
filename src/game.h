//
// Created by dalacroi on 21.11.2023.
//

#pragma once

#include "grid.h"
#include "blocks.cpp"



class Game {

private:
    Grid grid;

    std::vector<Block> blocks;
    Block currentBlock, nextBlock;
    bool isGameOver;
    int score;

    // Music Handling
    Music backgroundMusic;
    Sound rotateSound;
    Sound clearSound;

    // Input Handling
    void MoveBlockLeft();
    void MoveBlockRight();
    void LockBlock();

    void RotateBlock();
    bool BlockFits();
    void UpdateScore(int linesCleared, int moveDownPoints);

public:
    Game();
    ~Game();

    // Game Handling
    void Draw();
    void HandleInput();
    void Reset();

    // Input Handling
    void MoveBlockDown();

    // Game Logic Checks
    bool IsBlockOutside();
    bool IsGameOver();

    // Getters & Setters
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    int GetScore();
    Music GetBackgroundMusic();
};
