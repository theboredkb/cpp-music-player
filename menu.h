#pragma once
#include "songlist.h"

class Menu {
 private:
  SongList songList;

 public:
  Menu();

  void displayMenu();
  Song createSong();
  void selectOption(char option);
  void displayOpening();

    void searchMenu();
    void searchOption();
    
    void displayBar();
};
