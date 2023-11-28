#include <string>
using namespace std;

class Song{
    private:
        string artistName;
        string songTitle;
        string songGenre;
        string fileName;

        Song *prevSong;
        Song *nextSong;

    public:
        Song* getPrevSong();
        Song* getNextSong();
        void setPrevSong();
        void setNextSong();


        string getArtistName();
        void setArtistName();

        string getSongTitle();
        void setSongTitle();
        
        string getSongGenre();
        void setSongGenre();
        
        string getFileName();
        void setFileName();
 
}