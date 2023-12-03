#pragma once

#include "raylib.h"

class MusicHandler {

private:

    // Music tracks
    Music backgroundMusic;

    // Sounds
    Sound rotateSound;
    Sound clearSound;

    // Load Functions
    void LoadMusicTracks();
    void LoadSounds();

public:

    // Constructors
    MusicHandler();
    ~MusicHandler();

    // Play Functions
    void PlayBackgroundMusic();
    void PlayRotateSound();
    void PlayClearSound();

};


