//
// Created by dan10 on 19.11.2023.
//
#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

// Resources
Font font;

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

void LoadUIResources()
{
    font = LoadFontEx("../assets/fonts/monogram.ttf", 64, 0, 0);
}

void DrawUI(Game& game) {

    // Draw Score
    DrawTextEx(font, "Score", {350, 15}, 38, 2, WHITE);
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
    char scoreText[10];
    sprintf(scoreText, "%d", game.GetScore());
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, {320 + (170-textSize.x) / 2, 65}, 38, 2, WHITE);

    // Draw next block preview
    DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);


    // Draw game over
    if(game.IsGameOver()) {
        DrawTextEx(font, "GAME OVER", {320, 450}, 28, 2, WHITE);
    }
}

/**
 * MAIN
 */
int main()
{
    SetupWindow();
    LoadUIResources();

    Game game = Game();
    std::cout << "Current working directory: " << GetWorkingDirectory() << std::endl;
    std::cout << "Current application directory: " << GetApplicationDirectory() << std::endl;

    // Game loop
    while (!WindowShouldClose())
    {

        // Handle music and sounds
        UpdateMusicStream(game.GetBackgroundMusic());

        // Handle game input
        game.HandleInput();
        if(EventTriggered(0.4))
        {
            game.MoveBlockDown();
        }

        // Draw game UI
        BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawUI(game);
            game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}