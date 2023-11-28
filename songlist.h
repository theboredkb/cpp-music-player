#include "song.h"
using namespace std;

class SongList{
    private:
        Song *headSong;
        Song *tailSong;

    public:
        void printSong();
        void push_back();
        void insert_before();

        Song* getHeadSong();
        Song* getTailSong();
        void setHeadSong();
        void setTailSong();
    
}