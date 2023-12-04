#pragma once
#include "songlist.h"

class Player {
public:
  void playSong(Song currSong);
  bool pauseSong(Song currSong);
  bool stopSong(Song currSong);
};
