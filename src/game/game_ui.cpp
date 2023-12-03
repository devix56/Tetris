#include "game_ui.h"

GameUI::GameUI(Game* game, FontsHandler* fontsHandler)
{
    this->game = game;
    this->fontsHandler = fontsHandler;
}

void GameUI::DrawScore()
{
    // Get necessary resources
    Font mongram = fontsHandler->GetFontByName("Monogram");
    if(IsFontReady(mongram))
    {
        // Draw score text
        DrawTextEx(mongram, "Score", {350, 15}, 38, 2, WHITE);

        // Draw bounding box to display score inside
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        char scoreText[10];
        sprintf(scoreText, "%d", game->GetScore());

        // Draw score text inside bounding box
        Vector2 textSize = MeasureTextEx(mongram, scoreText, 38, 2);
        DrawTextEx(mongram, scoreText, {320 + (170-textSize.x) / 2, 65}, 38, 2, WHITE);
    }
}

void GameUI::DrawNextBlockPreview()
{
    // Get necessary resources
    Font mongram = fontsHandler->GetFontByName("Monogram");
    if(IsFontReady(mongram))
    {
        // Draw text
        DrawTextEx(mongram, "Next", {365, 175}, 38, 2, WHITE);

        // Draw bounding box
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        // Draw the next block inside bounding box
        Block& nextBlock = game->GetNextBlock();
        switch(nextBlock.GetId())
        {
            case 3:
                nextBlock.Draw(255, 290);
                break;
            case 4:
                nextBlock.Draw(255, 280);
                break;
            default:
                nextBlock.Draw(270, 270);
                break;
        }
    }
}

void GameUI::DrawGameOverText()
{
    // Get necessary resources
    Font mongram = fontsHandler->GetFontByName("Monogram");
    if(IsFontReady(mongram))
    {
        // Draw game over
        if (game->IsGameOver()) {
            DrawTextEx(mongram, "GAME OVER", {320, 450}, 28, 2, WHITE);
        }
    }
}

void GameUI::DrawPauseText()
{
    // Get necessary resources
    Font mongram = fontsHandler->GetFontByName("Monogram");
    if (IsFontReady(mongram))
    {
        // Draw game over
        if (game->isGamePaused()) {
            DrawTextEx(mongram, "GAME PAUSED", { 320, 450 }, 28, 2, WHITE);
        }
    }
}
