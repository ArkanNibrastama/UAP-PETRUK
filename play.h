#include <iostream>
#include <vector>
using namespace std;

struct Music{

    string judulLagu, penyanyi;

    Music *next;
    Music *prev;

};

Music *head, *tail, *cur, *newMusic;

void firstMusic(string judulLagu, string penyanyi){

    head = new Music();
    head->judulLagu = judulLagu;
    head->penyanyi = penyanyi;

    head->next = NULL;
    head->prev = NULL;

    tail = head;

}

void addMusic(string judulLagu, string penyanyi){

    newMusic = new Music();
    newMusic->judulLagu = judulLagu;
    newMusic->penyanyi = penyanyi;

    newMusic->next = NULL;
    newMusic->prev = tail;
    tail->next = newMusic;

    tail = newMusic;

}

void display(){

    int pil;
    bool exit = false, warning1 = false, warning2 = false;
    cur = head;

    do{

        system("cls");

        if (warning1 == true){

            cout << "playing now : " << cur->judulLagu <<"\n";
            cout << "Artist : " << cur->penyanyi << "\n";
            cout << "Playlistnya udah abis nih!" <<"\n";

        }
        else if (warning2 == true){

            cout << "playing now : " << cur->judulLagu <<"\n";
            cout << "Artist : " << cur->penyanyi << "\n";
            cout << "ini playlist pertama!" <<"\n";

        }else{

            cout << "playing now : " << cur->judulLagu <<"\n";
            cout << "Artist : " << cur->penyanyi << "\n";

        }

        cout << "1. Next" << "\n";
        cout << "2. Back" << "\n";
        cout << "3. Exit" << "\n";
        cout << "Pilihan : ";
        cin >> pil;

        if (pil == 1){

            if (cur->next == NULL){

                // cout << "Playlistnya udah abis nih!";
                warning1 = true;

            }else{

                cur = cur-> next;

            }

            warning2 = false;

        }
        else if (pil == 2){

            if (cur->prev == NULL){

                // cout << "ini playlist pertama!";
                warning2 = true;

            }else{

                cur = cur-> prev;

            }

            warning1 = false;

        }
        else if (pil == 3){

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
    for (auto j = song.begin(); j != song.end(); j++){

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
