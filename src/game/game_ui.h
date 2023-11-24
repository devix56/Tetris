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

    void DrawScore();                                   // Draws the score box
    void DrawNextBlockPreview();                        // Draws the preview for the next block
    void DrawGameOverText();                            // Draws the game over text when the player lost

public:
    GameUI() = delete;
    GameUI(Game* game, FontsHandler* fontsHandler);
    ~GameUI() = default;

    void DrawUI();                                      // Draws the whole game UI
};
