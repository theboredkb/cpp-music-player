#ifndef MENU_H
#define MENU_H

// #include "songlist.h"
class Menu {
private:
    // SongList songList;

public:
    void displayMenu();
    Song createSong();
    void selectOption(char option);
    void displayOpening();

    void displayBar();
};

#endif
