#include "game_ui.h"

GameUI::GameUI(Game* game, FontsHandler* fontsHandler)
{
    this->game = game;
    this->fontsHandler = fontsHandler;
}

void GameUI::DrawUI()
{
    DrawScore();
    DrawNextBlockPreview();
    DrawGameOverText();
}

void GameUI::DrawScore()
{

    Font mongram = fontsHandler->GetFontByName("Monogram");
    if(IsFontReady(mongram))
    {
        // Draw Score
        DrawTextEx(mongram, "Score", {350, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        char scoreText[10];
        sprintf(scoreText, "%d", game->GetScore());
        Vector2 textSize = MeasureTextEx(mongram, scoreText, 38, 2);
        DrawTextEx(mongram, scoreText, {320 + (170-textSize.x) / 2, 65}, 38, 2, WHITE);
    }

}

void GameUI::DrawNextBlockPreview()
{

    Font mongram = fontsHandler->GetFontByName("Monogram");
    if(IsFontReady(mongram))
    {
        // Draw next block preview
        DrawTextEx(mongram, "Next", {365, 175}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
    }
}

void GameUI::DrawGameOverText()
{
    Font mongram = fontsHandler->GetFontByName("Monogram");
    if(IsFontReady(mongram))
    {
        // Draw game over
        if (game->IsGameOver()) {
            DrawTextEx(mongram, "GAME OVER", {320, 450}, 28, 2, WHITE);
        }
    }
}
