//
// Created by dalacroi on 22.11.2023.
//
#pragma once

#ifndef TETRIS_FONTSHANDLER_H
#define TETRIS_FONTSHANDLER_H

#include <map>
#include <iostream>

#include "raylib.h"

class FontsHandler {

private:

    std::map<std::string, Font> fonts;

public:

    // Constructors
    FontsHandler();
    ~FontsHandler();

    // Functions
    Font GetFontByName(std::string fontName);
};


#endif //TETRIS_FONTSHANDLER_H
