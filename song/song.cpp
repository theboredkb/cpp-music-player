#include "song.h"


Song::Song(string title, string artist, string genre, string file) : prevSong(nullptr), nextSong(nullptr), songTitle(title), artistName(artist), songGenre(genre), fileName(file) {}

Song::Song(string title, string file) : prevSong(nullptr), nextSong(nullptr), songTitle(title), artistName(empty), songGenre(empty), fileName(file) {}

Song::Song(string title, string artist, string file) : prevSong(nullptr), nextSong(nullptr), songTitle(title), artistName(artist), songGenre(empty), fileName(file) {}

Song::Song(string title, string genre, string file) : prevSong(nullptr), nextSong(nullptr), songTitle(title), artistName(empty), songGenre(genre), fileName(file) {}

Song *Song::getPrevSong()
{
    return prevSong;
}

Song* Song::getNextSong()
{
    return nextSong;
}

void Song::setPrevSong(Song* node)
{
    prevSong = node;
}

void Song::setNextSong(Song* node)
{
    nextSong = node;
}


string Song::getSongTitle()
{
    return songTitle;
}

void Song::setSongTitle(string title)
{
    songTitle = title;
}

string Song::getArtistName()
{
    return artistName;
}

void Song::setArtistName(string artist)
{
    artistName = artist;
}

string Song::getSongGenre()
{
    return songGenre;
}

void Song::setSongGenre(string genre)
{
    songGenre = genre;
}

string Song::getFileName()
{
    return fileName;
}

void Song::setFileName(string file)
{
    fileName = file;
}
