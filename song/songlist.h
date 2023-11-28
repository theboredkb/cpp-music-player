#include "song.h"
using namespace std;

class SongList{
    private:
        Song *headSong;
        Song *tailSong;

    public:
        SongList();

        void printSong();
        void push_back();
        void insert_before();

        Song* getHeadSong();
        Song* getTailSong();
        void setHeadSong(Song* node);
        void setTailSong(Song* node);
    
};