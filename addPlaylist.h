#include <iostream>
#include <vector>
using namespace std;

vector <string> judulLagu;
vector <string> Penyanyi;
int playlistSize = 0;

bool notifSongHasAddedToPlaylist = false;

void addSong (string song, string artist){
	
	//untuk ngecek lagunya udah masuk playlist belum
    for(auto i = judulLagu.begin(); i != judulLagu.end(); i++){

        if (*i == song){
        	//kalo udah bakal keluar notif udah
            notifSongHasAddedToPlaylist = true;
            break;

        }

    }
    
//untuk nambahin lagu ke playlist
    if (notifSongHasAddedToPlaylist == false){

        judulLagu.push_back(song);
        penyanyi.push_back(artist);

        playlistSize += 1; //pertambahan lagu dari 0

    }
    

}

//untuk ngirim data lagu
vector <string> playlistSong(){
 return judulLagu;
}

vector <string> playlistArtist(){
 return penyanyi;
}
