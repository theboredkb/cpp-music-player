#include <string>
using namespace std;

class Song {
 private:
  string artistName;
  string songTitle;
  string songGenre;
  string songAlbum;
  string fileName;

  Song* prevSong;
  Song* nextSong;

 public:
  Song(string title, string artist, string genre, string album, string file);

  Song* getPrevSong();
  Song* getNextSong();
  void setPrevSong(Song* node);
  void setNextSong(Song* node);

  string getArtistName();
  void setArtistName(string artist);

  string getSongTitle();
  void setSongTitle(string title);

  string getSongGenre();
  void setSongGenre(string genre);

  string getSongAlbum();

  void setSongAlbum(string album);

  string getFileName();
  void setFileName(string file);
};
