//
// Created by dalacroi on 21.11.2023.
//

#include "game.h"

#include <random>


const int ROWS = 20;
const int COLUMNS = 10;
const int CELLSIZE = 30;

Game::Game(MusicHandler* musicHandler)
{
    grid = Grid(ROWS, COLUMNS, CELLSIZE);
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    isGameOver = false;
    score = 0;

    this->musicHandler = musicHandler;
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11, 11);
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();

    if(isGameOver && keyPressed != 0) {
        isGameOver = false;
        Reset();
    }

    switch(keyPressed)
    {
        case KEY_LEFT:
            MoveBlockLeft();
            break;

        case KEY_RIGHT:
            MoveBlockRight();
            break;

        case KEY_DOWN:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;

        case KEY_UP:
            RotateBlock();
            break;
        default:
            break;
    }

}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch(linesCleared)
    {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }

    score += moveDownPoints;
}

void Game::MoveBlockLeft()
{
    if(!isGameOver)
    {
        currentBlock.Move(0, -1);

        if(IsBlockOutside() || !BlockFits()) {
            currentBlock.Move(0, 1);
        }
    }

}

void Game::MoveBlockRight()
{
    if(!isGameOver)
    {
        currentBlock.Move(0, 1);

        if (IsBlockOutside() || !BlockFits()) {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if(!isGameOver)
    {
        currentBlock.Move(1, 0);

        if (IsBlockOutside() || !BlockFits()) {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for(Position item : tiles) {
        grid.SetCellValue(item.GetColumn(), item.GetRow(), currentBlock.GetId());
    }
    currentBlock = nextBlock;
    if(!BlockFits())
    {
        isGameOver = true;
    }

    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    if(rowsCleared > 0)
    {
        musicHandler->PlayClearSound();
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for(Position item : tiles)
    {
        if(grid.IsCellEmpty(item.GetRow(), item.GetColumn()) == false)
        {
            return false;
        }
    }

    return true;
}

void Game::RotateBlock()
{
    if(!isGameOver)
    {
        currentBlock.Rotate();

        if(IsBlockOutside())
        {
            currentBlock.UndoRotation();
        }

        else
        {
            musicHandler->PlayRotateSound();
        }

    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles)
    {
        if(grid.IsCellOutside(item.GetRow(), item.GetColumn())) return true;
    }

    return false;
}

bool Game::IsGameOver() const
{
    return this->isGameOver;
}

Block Game::GetRandomBlock()
{
    if(blocks.empty()) {
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

int Game::GetScore() const
{
    return this->score;
}

std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

Block& Game::GetNextBlock()
{
    return nextBlock;
}