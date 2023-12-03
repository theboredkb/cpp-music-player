#include <ctype.h>
#include <iostream>

#include "songlist.h"
#include "menu.h"

using namespace std;

Menu::Menu()
{
}

void Menu::displayOpening() {
  cout << "         //////////////////////////////////" << endl;
  cout << "         //                              //" << endl;
  cout << "         //         Music Player         //" << endl;
  cout << "         //              by              //" << endl;
  cout << "         //         Jia Jun Yang         //" << endl;
  cout << "         //         Elyod Abraham        //" << endl;
  cout << "         //         Kevin Ly             //" << endl;
  cout << "         //                              //" << endl;
  cout << "         //////////////////////////////////" << endl;
}



void Menu::displayMenu()
{
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
    cout << "Enter the artist of your song below: " << endl;
    cin >> songArtist;
    cout << "Enter the genre below: " << endl;
    cin >> songGenre;
    cout << "Enter the album below: " << endl;
    cin >> songAlbum;
    cout << "Enter the filename below: " << endl;
    cin >> songFile;
    

  } catch (string e) {
    cout << e << " cannot be empty!" << endl;
  }

  return Song(songTitle, songArtist, songGenre, songAlbum, songFile);
}

void Menu::displayBar() {
  cout << "////////////////////////////////////////////////////" << endl;
}

void Menu::selectOption(char option) {
  option = tolower(option);
  switch (option) {
    case 'a':
      // Add to Music List
      songList.push_back(createSong());
      
      
      break;
    case 'b':
      // Sort By Song
            

            songList.push_back(Song("Geddan", "Faa", "Pop", "Leggoo", "geddan.mp3"));
            songList.push_back(Song("B", "B", "B", "B", "b.mp3"));
        
      break;
    case 'c':
      // Sort By Genre
      break;
    case 'd':
      // Sort By Album
      break;
    case 'e':
      // List Current Order
      songList.printSong();
      break;
    case 'q':
      cout << "Exited." << endl;
      break;
    default:
      cout << "Invalid option - please try again." << endl;
  }
}
