#include "songlist.h"

SongList::SongList() : headSong(nullptr), tailSong(nullptr), sorted(nullptr) {}

void SongList::printSong()
{
    Song* current = headSong;

    while(current != nullptr){
        cout << "Song: " << current->getSongTitle() << ", Artist: " << current->getArtistName() << ", Genre: " << current->getSongGenre() << ", Album: " << current->getSongAlbum() << ", FileName: " << current->getFileName() << endl;

        current = current->getNextSong();
    }
}

void SongList::push_back(Song node)
{
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

Song* SongList::getSorted()
{
    return sorted;
}

void SongList::setSorted(Song *node)
{
    sorted = node;
}

void SongList::printSorted()
{   Song* current = sorted;

    while(current != nullptr){
        cout << current->getSongTitle() << endl;

        current = current->getNextSong();
    }
}

void SongList::resetSorted()
{
    Song* temp;
    while(sorted != nullptr){
        temp = sorted->getNextSong();
        delete sorted;
        sorted = temp;
    }
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

