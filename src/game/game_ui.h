#pragma once

#include "game.h"
#include "../resourcehandling/fontshandler.h"

/**
 * Draws all the UI elements for the game
 */
class GameUI {

private:

    Game* game;

    FontsHandler* fontsHandler;

public:
    GameUI() = delete;
    GameUI(Game* game, FontsHandler* fontsHandler);
    ~GameUI() = default;

    void DrawScore();                                   // Draws the score box
    void DrawNextBlockPreview();                        // Draws the preview for the next block
    void DrawGameOverText();                            // Draws the game over text when the player lost
    void DrawPauseText();                               // Draws the pause text when game is paused

};
