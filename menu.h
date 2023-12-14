#pragma once
#include "player.h"
#include "songlist.h"

class Menu : public BaseMenu {
 private:
  SongList songList;
  Player player;

 public:
  Menu();

  void displayMenu() override;
  Song createSong();
  void selectOption(char option) override;
  void displayOpening();
  void playSongList();

  void searchMenu();
  void searchOption();

  void displayBar() override;
};
