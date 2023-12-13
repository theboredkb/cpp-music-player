#include "menu.h"

#include <ctype.h>

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

Menu::Menu() {}

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

void Menu::displayMenu() {
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
  cout << "         //     (p) Play Song List       //" << endl;
  cout << "         //     (q) Exit                 //" << endl;
  cout << "         //////////////////////////////////" << endl;
}

void Menu::searchMenu() {
  cout << "         //////////////////////////////////" << endl;
  cout << "         //            Search            //" << endl;
  cout << "         //     (a) Sort By Song         //" << endl;
  cout << "         //     (b) Sort By Artist       //" << endl;
  cout << "         //     (c) Sort By Genre        //" << endl;
  cout << "         //     (d) Sort By Album        //" << endl;
  cout << "         //     (e) Sort By File Name    //" << endl;
  cout << "         //////////////////////////////////" << endl;
}

void Menu::searchOption() {
  searchMenu();
  char userOption;
  string userInput;

  cin >> userOption;

  userOption = tolower(userOption);

  cout << "Enter below: " << endl;
  cin >> userInput;
  switch (userOption) {
    case 'a':
      songList.searchSong(userInput);
      break;
    case 'b':
      songList.searchArtist(userInput);
      break;
    case 'c':
      songList.searchGenre(userInput);
      break;
    case 'd':
      songList.searchAlbum(userInput);
      break;
    case 'e':
      songList.searchFile(userInput);
      break;

    default:
      cout << "Invalid Option" << endl;
  }
}

Song Menu::createSong() {
  displayBar();

  // Used as a temporary fix to flush the cin buffer
  string init;

  string songTitle;
  string songArtist;
  string songGenre;
  string songAlbum;
  string songFile;

  try {
    // Temporary fix to flush it
    getline(cin, init);

    cout << "Enter your song title below: " << endl;
    getline(cin, songTitle);
    if (songTitle.empty()) throw string("Title");

    cout << "Enter the artist of your song below: " << endl;
    getline(cin, songArtist);
    if (songArtist.empty()) throw string("Artist");

    cout << "Enter the genre below: " << endl;
    getline(cin, songGenre);
    if (songGenre.empty()) throw string("Genre");

    cout << "Enter the album below: " << endl;
    getline(cin, songAlbum);

    cout << "Enter the filename below: " << endl;
    getline(cin, songFile);
    if (songFile.empty()) throw string("File");
    songFile = "songs/" + songFile;

  } catch (string e) {
    cout << e << " of the song cannot be empty!" << endl;
  }

  return Song(songTitle, songArtist, songGenre, songAlbum, songFile);
}

void Menu::playSongList() {
  cout << "These are the songs in your list: " << endl;
  songList.printSong();

  Song *songHead = songList.getHeadSong();
  if (songHead == nullptr) {
    cout << "No songs in list." << endl;
    return;
  }

  while (songHead != nullptr) {
    player.loadSong(songHead->getFileName());
    displayBar();
    cout << "Playing " << songHead->getSongTitle() << " by "
         << songHead->getArtistName() << endl;
    displayBar();
    float songDuration = player.getSongLength();
    // float songDuration = 10.00;
    while (songDuration > 0) {
      sleep(1);
      cout << "Song duration: " << songDuration << endl;
      songDuration -= 1;
    }

    // player.stopSong();
    songHead = songHead->getNextSong();
  }
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
      songList.sortGenre();

      break;
    case 'e':
      // Sort By Album
      songList.sortAlbum();

      break;

    case 'f':
      // Sort By File Name
      songList.sortFile();

      break;

    case 'g':
      // List Current Order
      songList.printSong();
      break;

    case 'h':
      searchMenu();
      break;

    case 'p':
      // Play Song
      playSongList();
      break;

    case 'q':
      cout << "Exited." << endl;
      break;
    default:
      cout << "Invalid option - please try again." << endl;
  }
}
