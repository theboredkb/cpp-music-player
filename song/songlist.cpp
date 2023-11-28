#include "songlist.h"

SongList::SongList() {}

void SongList::setHeadSong(Song* node)
{
    headSong = node;
}

void SongList::setTailSong(Song* node)
{
    tailSong = node;
}
