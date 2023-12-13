#pragma once
// #include "player.h"
#include "songlist.h"

class Menu {
 private:
  SongList songList;
  // Player player;

 public:
  Menu();

  void displayMenu();
  Song createSong();
  void selectOption(char option);
  void displayOpening();
  void playSongList();

  void searchMenu();
  void searchOption();

  void displayBar();
};
