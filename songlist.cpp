#include "songlist.h"

SongList::SongList() : headSong(nullptr), tailSong(nullptr), sorted(nullptr) {}

void SongList::printSong() {
  Song* currentSong = headSong;

  while (currentSong != nullptr) {
    cout << "Song: " << currentSong->getSongTitle()
         << ", Artist: " << currentSong->getArtistName()
         << ", Genre: " << currentSong->getSongGenre()
         << ", Album: " << currentSong->getSongAlbum()
         << ", FileName: " << currentSong->getFileName() << endl;

    currentSong = currentSong->getNextSong();
  }
  cout << endl;
}

void SongList::push_back(Song node) {
  Song* tempNode = new Song(node);

  if (getHeadSong() == nullptr) {
    setHeadSong(tempNode);
    setTailSong(tempNode);
  } else {
    tailSong->setNextSong(tempNode);

    tempNode->setPrevSong(tailSong);
    setTailSong(tempNode);
  }
}

Song* SongList::getHeadSong() { return headSong; }

Song* SongList::getTailSong() { return tailSong; }

void SongList::setHeadSong(Song* node) { headSong = node; }

void SongList::setTailSong(Song* node) { tailSong = node; }

Song* SongList::getSorted() { return sorted; }

void SongList::setSorted(Song* node) { sorted = node; }

void SongList::resetSorted(){
  Song* current = sorted;
  while (current != nullptr) {
    Song* temp = current->getNextSong();
    delete current;
    current = temp;
  }
  sorted = nullptr;
}

void SongList::searchSong(string word)
{
    Song* currentSong = headSong;
    bool isExist = false;

  while (currentSong != nullptr) {
    if(currentSong->getSongTitle() == word){ isExist = true; }
    currentSong = currentSong->getNextSong();
  }
  if(isExist){ 
    cout << "Song is in the List" << endl;
  }
  else{ cout << "Not found in the song list" << endl; }
  cout << endl;
}

void SongList::searchArtist(string word)
{
    Song* currentSong = headSong;
    bool isExist = false;

  while (currentSong != nullptr) {
    if(currentSong->getArtistName() == word){ isExist = true; }
    currentSong = currentSong->getNextSong();
  }
  if(isExist){ 
    cout << "Artist is in the List" << endl;
  }
  else{ cout << "Not found in the song list" << endl; }
  cout << endl;
}

void SongList::searchGenre(string word)
{
    Song* currentSong = headSong;
    bool isExist = false;

  while (currentSong != nullptr) {
    if(currentSong->getSongGenre() == word){ isExist = true; }
    currentSong = currentSong->getNextSong();
  }
  if(isExist){ 
    cout << "Genre is in the List" << endl;
  }
  else{ cout << "Not found in the song list" << endl; }
  cout << endl;
}

void SongList::searchAlbum(string word)
{
    Song* currentSong = headSong;
    bool isExist = false;

  while (currentSong != nullptr) {
    if(currentSong->getSongAlbum() == word){ isExist = true; }
    currentSong = currentSong->getNextSong();
  }
  if(isExist){ 
    cout << "Album is in the List" << endl;
  }
  else{ cout << "Not found in the song list" << endl; }
  cout << endl;
}

void SongList::searchFile(string word)
{
    Song* currentSong = headSong;
    bool isExist = false;

  while (currentSong != nullptr) {
    if(currentSong->getFileName() == word){ isExist = true; }
    currentSong = currentSong->getNextSong();
  }
  if(isExist){ 
    cout << "File is in the List" << endl;
  }
  else{ cout << "Not found in the song list" << endl; }
  cout << endl;
}




////////////////////////////////////////////////////////////////////Printing
///Sorts

void SongList::printSortedSong() {
  Song* current = sorted;

  while (current != nullptr) {
    cout << current->getSongTitle() << endl;

    current = current->getNextSong();
  }
}

void SongList::printSortedArtist() {
  Song* current = sorted;

  while (current != nullptr) {
    cout << current->getArtistName() << endl;

    current = current->getNextSong();
  }
}

void SongList::printSortedGenre() {
  Song* current = sorted;

  while (current != nullptr) {
    cout << current->getSongGenre() << endl;

    current = current->getNextSong();
  }
}

void SongList::printSortedAlbum() {
  Song* current = sorted;

  while (current != nullptr) {
    cout << current->getSongAlbum() << endl;

    current = current->getNextSong();
  }
}

void SongList::printSortedFile() {
  Song* current = sorted;

  while (current != nullptr) {
    cout << current->getFileName() << endl;

    current = current->getNextSong();
  }
}

/////////////////////////////////////////////////////////////////Sorting

void SongList::sortTitle() {
  SongList sortedList; 
  Song* current = headSong;

  cout << ":::Sorted by Song:::" << endl;
  while (current != nullptr) {
    Song* next = current->getNextSong();
    sortedList.sortInsertTitle(new Song(*current));
    current = next;
  }
  sortedList.printSortedSong();
}

void SongList::sortInsertTitle(Song* node) {
  if (sorted == nullptr || sorted->getSongTitle() > node->getSongTitle()) {
    node->setNextSong(sorted);
    sorted = node;
  } else {
    Song* current = sorted;

    while (current->getNextSong() != nullptr &&
           current->getNextSong()->getSongTitle() < node->getSongTitle()) {
      current = current->getNextSong();
    }
    node->setNextSong(current->getNextSong());
    current->setNextSong(node);
  }
}

void SongList::sortArtist() {
  SongList sortedList;  
  Song* current = headSong;

  cout << ":::Sorted by Artist:::" << endl;
  while (current != nullptr) {
    Song* next = current->getNextSong();
    sortedList.sortInsertArtist(new Song(*current));  
    current = next;
  }

  sortedList.printSortedArtist();  
}

void SongList::sortInsertArtist(Song* node) {
  if (sorted == nullptr || sorted->getArtistName() > node->getArtistName()) {
    node->setNextSong(sorted);
    sorted = node;
  } else {
    Song* current = sorted;

    while (current->getNextSong() != nullptr &&
           current->getNextSong()->getArtistName() < node->getArtistName()) {
      current = current->getNextSong();
    }
    node->setNextSong(current->getNextSong());
    current->setNextSong(node);
  }
}

void SongList::sortGenre() {}

void SongList::sortInsertGenre(Song* node) {}

void SongList::sortAlbum() {}

void SongList::sortInsertAlbum(Song* node) {}

void SongList::sortFile() {}

void SongList::sortInsertFile(Song* node) {}
