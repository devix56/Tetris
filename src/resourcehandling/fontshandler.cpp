//
// Created by dalacroi on 22.11.2023.
//

#include "fontshandler.h"

FontsHandler::FontsHandler()
{
    // Load all fonts
    fonts = {
        {"Monogram", LoadFontEx("assets/fonts/monogram.ttf", 64, 0, 0)},
    };
}

FontsHandler::~FontsHandler()
{
    // Unload all fonts
    for (auto& font : fonts) {
        UnloadFont(font.second);
        fonts.erase(font.first);
    }
}

Font FontsHandler::GetFontByName(std::string fontName)
{
    Font font = fonts.at(fontName);

    if(IsFontReady(font))
    {
        return font;
    }
}
