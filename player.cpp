#include "player.h"
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

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

  const char* cPath = fileName.c_str();

  if ((*this).songLoaded) {
    ma_sound_uninit(&(*this).currentSong);
  }

  (*this).songLoaded = false;

  result = ma_sound_init_from_file(&engine, cPath, 0, NULL, NULL,
                                   &(*this).currentSong);
  if (result != MA_SUCCESS) {
    cout << "Warning! Song could not be loaded." << endl;
  } else {
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

float Player::getSongLength() {
  float length;
  if ((*this).songLoaded) {
    ma_data_source_get_length_in_seconds(&(*this).currentSong, &length);
    return length;
  } else {
    return 0;
  }
}