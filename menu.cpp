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
    cout << "         //     (c) Sort By Artist       //" << endl;
    cout << "         //     (d) Sort By Genre        //" << endl;
    cout << "         //     (e) Sort By Album        //" << endl;
    cout << "         //     (f) Sort By File Name    //" << endl;
    cout << "         //     (g) List Current Order   //" << endl;
    cout << "         //     (h) Search Song List     //" << endl;
    cout << "         //     (q) Exit                 //" << endl;
    cout << "         //////////////////////////////////" << endl;
}

void Menu::searchMenu()
{
    cout << "         //////////////////////////////////" << endl;
    cout << "         //            Search            //" << endl;
    cout << "         //     (a) Sort By Song         //" << endl;
    cout << "         //     (b) Sort By Artist       //" << endl;
    cout << "         //     (c) Sort By Genre        //" << endl;
    cout << "         //     (d) Sort By Album        //" << endl;
    cout << "         //     (e) Sort By File Name    //" << endl;
    cout << "         //////////////////////////////////" << endl;
}

void Menu::searchOption()
{
  char userOption;
  char userInput;

  cin >> userOption;


  userOption = tolower(userOption);
  
    cout << "Enter below: " << endl;
  switch(userOption) {
    case 'a':
    break;
    case 'b':
    break;
    case 'c':
    break;
    case 'd':
    break;
    case 'e':
    break;
    
    default:
    cout << "Not found in the song list" << endl;
  }
}

Song Menu::createSong() {
  displayBar();
  string songTitle;
  string songArtist;
  string songGenre;
  string songAlbum;
  string songFile;

  try {
    getline(cin, songTitle);

    cout << "Enter your song title below: " << endl;
    getline(cin, songTitle);

    cout << "Enter the artist of your song below: " << endl;
    getline(cin, songArtist);

    cout << "Enter the genre below: " << endl;
    getline(cin, songGenre);

    cout << "Enter the album below: " << endl;
    getline(cin, songAlbum);
    
    cout << "Enter the filename below: " << endl;
    getline(cin, songFile);
    

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
      songList.sortTitle();

        
      break;
    case 'c':
      // Sort By Artist
      songList.sortArtist();

      break;
    case 'd':
      // Sort By Genre
      //songList.sortGenre();

      break;
    case 'e':
      // Sort By Album
      //songList.sortAlbum();

      break;

    case 'f':
      // Sort By File Name
      //songList.sortFile();
      
      break;

    case 'g':
      // List Current Order
      songList.printSong();
      break;

    case 'h':
      searchMenu();
      break;

    case 'q':
      cout << "Exited." << endl;
      break;
    default:
      cout << "Invalid option - please try again." << endl;
  }
}
