#include "menu.h"

#include <ctype.h>

#include <iostream>

#include "songlist.h"

using namespace std;

void Menu::displayOpening() {
  cout << "     //////////////////////////////////" << endl;
  cout << "     //                              //" << endl;
  cout << "     //         Music Player         //" << endl;
  cout << "     //              by              //" << endl;
  cout << "     //         Jia Jun Yang         //" << endl;
  cout << "     //         Cindy He             //" << endl;
  cout << "     //         Elyod Abraham        //" << endl;
  cout << "     //         Kevin Ly             //" << endl;
  cout << "     //                              //" << endl;
  cout << "     //////////////////////////////////" << endl;
}

void Menu::displayMenu() {
  cout << "         //////////////////////////////////" << endl;
  cout << "         //             Menu             //" << endl;
  cout << "         //     (a) Add to Music List    //" << endl;
  cout << "         //     (b) Sort By Song         //" << endl;
  cout << "         //     (c) Sort By Genre        //" << endl;
  cout << "         //     (d) Sort By Album        //" << endl;
  cout << "         //     (e) List Current Order   //" << endl;
  cout << "         //     (q) Exit                 //" << endl;
  cout << "         //////////////////////////////////" << endl;
}

Song Menu::createSong() {
  displayBar();
  string songTitle;
  string songArtist;
  string songGenre;
  string songAlbum;
  string songFile;

  try {
    cout << "Enter your song title below: " << endl;
    cin >> songTitle;
    if (songTitle == "") throw songTitle;
    cout << "Enter the artist of your song below: " << endl;
    cin >> songArtist;
    if (songArtist == "") throw songArtist;
    cout << "Enter the genre of your song below: " << endl;
    cin >> songGenre;
    if (songGenre == "") throw songArtist;
    cout << "Enter the file name of your song below: " << endl;
    cin >> songFile;
    if (songFile == "") throw songArtist;
  } catch (string e) {
    cout << e << " cannot be empty!" << endl;
  }

  return Song(songTitle, songArtist, songGenre, songFile);
}

void Menu::displayBar() {
  cout << "////////////////////////////////////////////" << endl;
}

void Menu::selectOption(char option) {
  option = tolower(option);
  switch (option) {
    case 'a':
      // Add to Music List
      break;
    case 'b':
      // Sort By Song
      break;
    case 'c':
      // Sort By Genre
      break;
    case 'd':
      // Sort By Album
      break;
    case 'e':
      // List Current Order
      break;
    case 'q':
      cout << "Exited." << endl;
      break;
    default:
      cout << "Invalid option - please try again." << endl;
  }
}
