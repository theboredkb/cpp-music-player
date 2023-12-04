#include "player.h"

void Player::playSong(string fileName) {
  // Temporary testing sound player until class is implemented

  ma_result result;
  ma_engine engine;
  ma_sound sound;

  string filePath = "/music/" + fileName;

  result = ma_engine_init(NULL, &engine);
  if (result != MA_SUCCESS) {
    cout << "Warning! Song engine could not be started." << endl;
    return;
  }

  const char* cPath = filePath.c_str();

  result = ma_sound_init_from_file(&engine, cPath, 0, NULL, NULL, &sound);
}