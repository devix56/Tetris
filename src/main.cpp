//
// Created by dan10 on 19.11.2023.
//
#include "raylib.h"
#include "game/game.h"
#include "util/colors.h"
#include "resourcehandling/fontshandler.h"
#include "game/game_ui.h"

// Handlers
MusicHandler* musicHandler;
FontsHandler* fontsHandler;
Game* game;
GameUI* gameUI;

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


/**
 * MAIN
 */
int main()
{
    SetupWindow();
    musicHandler = new MusicHandler();
    fontsHandler = new FontsHandler();

    game = new Game(musicHandler);
    gameUI = new GameUI(game, fontsHandler);

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
            gameUI->DrawUI();
            game->Draw();
        EndDrawing();
    }

    // Cleanup
    delete musicHandler;
    delete fontsHandler;
    delete game;
    delete gameUI;

    CloseWindow();

    return 0;
}