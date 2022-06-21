#include <iostream>
#include <vector>
using namespace std;

struct Music{

    string judulLagu, penyanyi;

    Music *next;

};

Music *head, *tail, *cur, *newMusic, *rmv;

void firstMusic(string judulLagu, string penyanyi){

    head = new Music();
    head->judulLagu = judulLagu;
    head->penyanyi = penyanyi;

    head->next = NULL;

    tail = head;

}

void addMusic(string judulLagu, string penyanyi){

    newMusic = new Music();
    newMusic->judulLagu = judulLagu;
    newMusic->penyanyi = penyanyi;

    newMusic->next = NULL;
    tail->next = newMusic;

    tail = newMusic;

}

void remove(){

    rmv = head;
    head = head->next;
    delete rmv;

}

void display(){

    int pil;
    bool exit = false, warning = false;

    do{

        cur = head;

        system("cls");

        if (warning == true){

            cout << "(Playlistnya udah abis nih!)" <<"\n";

        }else{

            cout << "playing now : " << cur->judulLagu <<"\n";
            cout << "Artist : " << cur->penyanyi << "\n";

        }

        cout << "1. Putar lagu selanjutnya!" << "\n";
        cout << "2. Exit" << "\n";
        cout << "Pilihan : ";
        cin >> pil;

        if (pil == 1){

            if (cur->next == NULL){

                warning = true;

            }else{

                remove();

            }

        }
        else if (pil == 2){

             exit = true;

        }else{

            cout << "Pilihan tidak ada!";

        }


    }while(exit == false);

}


//pake vector kyknya nanti
void Play(vector<string> song, vector<string> artist, int n){

    string arrSong[n], arrArtist[n];
    int c1 = 0, c2 = 0;

    for (auto i = song.begin(); i != song.end(); i++){

        arrSong[c1] = *i;
        c1 += 1;

    }
    for (auto j = artist.begin(); j != artist.end(); j++){

        arrArtist[c2] = *j;
        c2 += 1;

    }

    for (int k = 0; k < n; k++){

        if (k == 0){

            firstMusic(arrSong[k], arrArtist[k]);

        }else{

            addMusic(arrSong[k], arrArtist[k]);

        }

    }

    display();

}
