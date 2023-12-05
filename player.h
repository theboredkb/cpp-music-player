#pragma once
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "songlist.h"

class Player {
 private:
  ma_engine engine;
  ma_sound currentSong;
  bool songLoaded;

 public:
  Player();
  ~Player();

  void loadSong(string fileName);
  void playSong();
  void stopSong();
  float getSongLength();
};