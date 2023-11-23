//
// Created by dalacroi on 22.11.2023.
//

#define DEBUG_LOGGING

#include "musichandler.h"

#include <iostream>

MusicHandler::MusicHandler()
{
    InitAudioDevice();
    SetMasterVolume(100);

    // Load music & sound resources
    LoadMusicTracks();
    LoadSounds();
}

MusicHandler::~MusicHandler()
{
    // Unload everything
    UnloadMusicStream(backgroundMusic);
    UnloadSound(clearSound);
    UnloadSound(rotateSound);

    CloseAudioDevice();
}

void MusicHandler::LoadMusicTracks()
{
    backgroundMusic = LoadMusicStream("../assets/sounds/music.mp3");
}

void MusicHandler::LoadSounds()
{
    rotateSound = LoadSound("../assets/sounds/rotate.mp3");
    clearSound = LoadSound("../assets/sounds/clear.mp3");
}

void MusicHandler::PlayRotateSound()
{
    if(IsAudioDeviceReady() && IsSoundReady(rotateSound))
    {
        #if DEBUG_LOGGING TRUE
            std::cout << "Playing rotate sound..." << std::endl;
        #endif
        PlaySound(rotateSound);
    }
}

void MusicHandler::PlayClearSound()
{
    if(IsAudioDeviceReady() && IsSoundReady(clearSound))
    {
        #if DEBUG_LOGGING TRUE
                std::cout << "Playing clear sound..." << std::endl;
        #endif
        PlaySound(clearSound);
    }
}

void MusicHandler::PlayBackgroundMusic()
{
    if(IsMusicStreamPlaying(backgroundMusic))
    {
        UpdateMusicStream(backgroundMusic);
        return;
    }

    if(IsAudioDeviceReady() && IsMusicReady(backgroundMusic))
    {
        #if DEBUG_LOGGING TRUE
            std::cout << "Starting background music..." << std::endl;
        #endif
        PlayMusicStream(backgroundMusic);
    }

}