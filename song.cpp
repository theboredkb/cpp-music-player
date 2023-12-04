#include "song.h"

Song::Song(string title, string artist, string genre, string album, string file) : songTitle(title), artistName(artist), songGenre(genre), songAlbum(album), fileName(file), nextSong(nullptr), prevSong(nullptr) {}

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

string Song::getSongAlbum()
{
    return songAlbum;
}

void Song::setSongAlbum(string album)
{
    songAlbum = album;
}

string Song::getFileName()
{
    return fileName;
}

void Song::setFileName(string file)
{
    fileName = file;
}
