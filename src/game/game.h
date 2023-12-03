#pragma once

#include "../grid/grid.h"
#include "../block/blocks.cpp"
#include "../resourcehandling/musichandler.h"

class Game {

private:

    // Game attributes
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock, nextBlock;
    bool isGameOver;
    int score;
    bool paused;

    // Resources
    MusicHandler* musicHandler;

    // Input Handling
    void MoveBlockLeft();
    void MoveBlockRight();

    // Game Logic
    void LockBlock();
    void RotateBlock();
    bool BlockFits();
    void UpdateScore(int linesCleared, int moveDownPoints);

public:
    Game(MusicHandler* musicHandler);

    // Game Handling
    void Draw();
    void HandleInput();
    void Reset();

    // Input Handling
    void MoveBlockDown();

    // Game Logic Checks
    bool IsBlockOutside();
    bool IsGameOver() const;


    // Getters & Setters
    Block GetRandomBlock();
    static std::vector<Block> GetAllBlocks();
    int GetScore() const;
    Block &GetNextBlock();
    bool isGamePaused();
};
