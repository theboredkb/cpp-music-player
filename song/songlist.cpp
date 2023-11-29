#include "songlist.h"

SongList::SongList() : headSong(nullptr), tailSong(nullptr), sorted(nullptr) {}

void SongList::printSong()
{
}

void SongList::push_back(string title, string artist, string  genre, string file)
{
    Song* tempNode = new Song(title, artist, genre, file);
    if (headSong == nullptr) {
        headSong = tempNode;
    } else {
        tailSong->setNextSong(tempNode);
        tempNode->setPrevSong(tailSong);
        tailSong = tempNode;
    }
}

void SongList::insert_before()
{
}



Song* SongList::getHeadSong()
{
    return headSong;
}

Song* SongList::getTailSong()
{
    return tailSong;
}

void SongList::setHeadSong(Song* node)
{
    headSong = node;
}

void SongList::setTailSong(Song* node)
{
    tailSong = node;
}

Song *SongList::getSorted()
{
    return sorted;
}

void SongList::setSorted(Song *node)
{
    sorted = node;
}

void SongList::sortTitle()
{
    sorted = nullptr;
    Song* current = headSong;

    while(current != nullptr){
        Song* next = current->getNextSong();

        sortInsertTitle(current);

        current = next;

    }

}

void SongList::sortInsertTitle(Song* node){
    if (sorted == nullptr || sorted->getSongTitle() > node->getSongTitle()) { 
            node->setNextSong(sorted); 
            sorted = node; 
        } 
        else { 
            Song* current = sorted; 

            while (current->getNextSong() != nullptr && current->getNextSong()->getSongTitle() < node->getSongTitle()) { 
                current = current->getNextSong(); 
            } 
            node->setNextSong(current->getNextSong()); 
            current->setNextSong(node); 
        } 
}

