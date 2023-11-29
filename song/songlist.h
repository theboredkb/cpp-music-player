#include "song.h"
using namespace std;

class SongList{
    private:
        Song* headSong;
        Song* tailSong;

        Song* sorted;

    public:
        SongList();

        void printSong();
        void push_back(string title, string artist, string  genre, string file);
        void insert_before();

        Song* getHeadSong();
        Song* getTailSong();
        void setHeadSong(Song* node);
        void setTailSong(Song* node);

        Song* getSorted();
        void setSorted(Song* node);

        /// Sort ///////////////////////////////////// Check if this works before duplicate
        void sortTitle();
        void sortInsertTitle(Song* node);
    
};