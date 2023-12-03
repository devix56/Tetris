#include "raylib.h"
#include "raymath.h"
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
double currentInterval = 0.6;                       // Time to wait to move block down automatically in seconds
const int INCREASE_SPEED_INTERVAL = 30;             // Time to wait to increase block fall speed in seconds
const double MAX_FALL_SPEED = 0.15;                 // Maximum fall speed for the blocks
bool EventTriggered()
{
    const bool SHOULD_UPDATE_FALL_SPEED = (int) GetTime() % INCREASE_SPEED_INTERVAL == 0; // Checks if set time has passed to increase block fall speed
    const double CURRENT_TIME = GetTime();                                                // Current time that has passed since start of the game

    const bool HAS_INTERVAL_PASSED = CURRENT_TIME - lastUpdateTime >= currentInterval;    // Checks if enough time has passed to move block down
    const bool IS_MAX_SPEED_REACHED = currentInterval <= MAX_FALL_SPEED;                  // Checks if the maximum block fall speed has been reached

    if(HAS_INTERVAL_PASSED)
    {
        if (SHOULD_UPDATE_FALL_SPEED && !IS_MAX_SPEED_REACHED)
        {
            currentInterval -= 0.05;    // Reduce time (= increase speed) to wait to move block down
        }

        lastUpdateTime = CURRENT_TIME;  // Save last time the fall speed has been updated

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

        if(!game->isGamePaused()) 
        {
            musicHandler->PlayBackgroundMusic();

            // Handle game input
            game->HandleInput();
            if (WindowShouldClose()) {
                break;
            }

            if (EventTriggered())
            {
                game->MoveBlockDown();
            }

            // Draw game UI
            BeginDrawing();
                ClearBackground(DARKBLUE);
                gameUI->DrawScore();
                gameUI->DrawNextBlockPreview();
                gameUI->DrawGameOverText();
                game->Draw();
            EndDrawing();
        }

        else 
        {   
            game->HandleInput();
            BeginDrawing();
                gameUI->DrawPauseText();
            EndDrawing();
        }

    }

    // Cleanup
    delete musicHandler;
    delete fontsHandler;
    delete game;
    delete gameUI;

    CloseWindow();

    return 0;
}