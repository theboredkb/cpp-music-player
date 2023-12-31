#pragma once
#include <iostream>

#include "song.h"
using namespace std;

class SongList {
 private:
  Song* headSong;
  Song* tailSong;

  Song* sorted;

 public:
  SongList();

  void printSong();
  void push_back(Song node);

  Song* getHeadSong();
  Song* getTailSong();
  void setHeadSong(Song* node);
  void setTailSong(Song* node);

  Song* getSorted();
  void setSorted(Song* node);
  void printSortedFunc();

  void resetSorted();

  void searchSong(string word);
  void searchArtist(string word);
  void searchGenre(string word);
  void searchAlbum(string word);
  void searchFile(string word);

  /// Sort ///////////////////////////////////// Check if this works before
  /// duplicate
  void sortTitle();
  void sortInsertTitle(Song* node);

  void sortArtist();
  void sortInsertArtist(Song* node);

  void sortGenre();
  void sortInsertGenre(Song* node);

  void sortAlbum();
  void sortInsertAlbum(Song* node);

  void sortFile();
  void sortInsertFile(Song* node);
};
