#include <iostream>
#include <vector>

using namespace std;

vector<string> judulLagu;
vector<string> penyanyi;
int playlistSize = 0;

bool notifSongHasAddedToPlaylist = false;

void addSong(string song, string artist){


    for (auto i = judulLagu.begin(); i != judulLagu.end(); i++){

        if (*i == song){

            notifSongHasAddedToPlaylist = true;
            break;

        }

    }

    if (notifSongHasAddedToPlaylist == false){

        judulLagu.push_back(song);
        penyanyi.push_back(artist);

        playlistSize += 1;

    }
    

}

vector<string> playlistSong(){

 return judulLagu;

}

vector<string> playlistArtist(){

 return penyanyi;

}


//gambaran di fungsi Play
// int main(){

//    addSong("marigorudo", "aimyon");

//    for (auto i = judulLagu.begin(); i != judulLagu.end(); i++){

//         cout << *i << "\n";

//    }

// }

