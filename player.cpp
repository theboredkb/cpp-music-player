#include "player.h"

Player::Player() {
  (*this).songLoaded = false;
  if (ma_engine_init(NULL, &(*this).engine) != MA_SUCCESS) {
    cout << "Warning! Song engine could not be started." << endl;
  }
}

Player::~Player() {
  if ((*this).songLoaded) {
    ma_sound_uninit(&(*this).currentSong);
  }
  ma_engine_uninit(&(*this).engine);
}

void Player::loadSong(string fileName) {
  ma_result result;
  ma_sound sound;

  const char* cPath = fileName.c_str();

  if ((*this).songLoaded) {
    ma_sound_uninit(&(*this).currentSong);
  }

  (*this).songLoaded = false;

  result = ma_sound_init_from_file(&engine, cPath, 0, NULL, NULL, &sound);
  if (result != MA_SUCCESS) {
    cout << "Warning! Song could not be loaded." << endl;
  } else {
    (*this).currentSong = sound;
    (*this).songLoaded = true;
  }
}

void Player::playSong() {
  if ((*this).songLoaded) {
    ma_sound_start(&(*this).currentSong);
  }
}

void Player::stopSong() {
  if ((*this).songLoaded) {
    ma_sound_stop(&(*this).currentSong);
    ma_sound_uninit(&(*this).currentSong);
    (*this).songLoaded = false;
  }
}