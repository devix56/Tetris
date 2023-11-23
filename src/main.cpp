//
// Created by dan10 on 19.11.2023.
//
#include "raylib.h"
#include "game/game.h"
#include "util/colors.h"
#include "resourcehandling/fontshandler.h"
#include <iostream>

// Handlers
MusicHandler* musicHandler;
FontsHandler* fontsHandler;

// Event Triggers
double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();

    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

void SetupWindow()
{
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);
}


void DrawUI(Game* game, FontsHandler* fontsHandler) {

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

        // Draw next block preview
        DrawTextEx(mongram, "Next", {365, 175}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);


        // Draw game over
        if(game->IsGameOver()) {
            DrawTextEx(mongram, "GAME OVER", {320, 450}, 28, 2, WHITE);
        }
    }


}

/**
 * MAIN
 */
int main()
{
    SetupWindow();
    musicHandler = new MusicHandler();
    fontsHandler = new FontsHandler();

    Game* game = new Game(musicHandler);

    // Game loop
    while (!WindowShouldClose())
    {
        musicHandler->PlayBackgroundMusic();

        // Handle game input
        game->HandleInput();
        if(EventTriggered(0.4))
        {
            game->MoveBlockDown();
        }

        // Draw game UI
        BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawUI(game, fontsHandler);
            game->Draw();
        EndDrawing();
    }

    // Cleanup
    delete musicHandler;
    delete fontsHandler;
    delete game;

    CloseWindow();

    return 0;
}