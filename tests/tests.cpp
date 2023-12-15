#include <iostream>
#include <cassert>

#include "song.h"
#include "songlist.h"

int main(){
    Song song1("Title1", "Artist1", "Genre1", "File1", "File1.mp3");

    assert(song1.getSongTitle() == "Title1");
    assert(song1.getArtistName() == "Artist1");
    assert(song1.getSongGenre() == "Genre1");
    assert(song1.getSongAlbum() == "File1");
    assert(song1.getFileName() == "File1.mp3");

    SongList songList;

    songList.push_back(song1);

    Song song3("Song3", "Artist3", "Genre3",  "File3", "File3.mp3");
    songList.push_back(song3);

    Song song2("Song2", "Artist2", "Genre2", "File2", "File2.mp3");
    songList.push_back(song2);

    assert(songList.getHeadSong()->getSongTitle() == "Title1");
    assert(songList.getTailSong()->getSongTitle() == "Song2");

    cout << "Print Songlist" << endl;
    songList.printSong();

    cout << "Check sorted by genre: " << endl;
    songList.sortGenre();
    songList.printSortedFunc();
}