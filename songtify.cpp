#include <iostream>
#include "addPlaylist.h"
#include "play.h"

using namespace std;

void header(){
	cout << "=====================================================" << "\n";
    cout << "                        SONGTIFY " << "\n";
    cout << "=====================================================" << "\n";
    cout<<"                  Enjoy Your Music Here!"<<"\n\n";
}
void footer(){
	cout<<"===================================================="<<"\n";
}
void SongList(string Judul, string Penyanyi, string Album, string rilis){
	system("cls");
	header();
	
	cout<<"\nJudul\t\t: \""<<Judul<<"\"\n";
	cout<<"Album\t\t: "<<Album<<"\n";
	cout<<"tPenyanyi\t: "<<Penyanyi<<"\n";
	cout<<"Tahun Rilis\t: "<<rilis<<"\n\n";
	footer();
}

int Pilih(int c, int n, bool u, bool n1, bool n2){

    string pilih;
    int next = 1;
    int back = 2;
    int add = 3;
    int home = 4;
    int ulang = 5;

    if (u == true){

        cout << "(Pilihan tidak tersedia! harap ulangi kembali.)" << "\n";

    }

    if (n2 == true){

        n1 = false;

    }

    if (n1 == true){

        cout << "(yeay, Playlist berhasil dimasukkan!)" << "\n";

    }

    if (n2 == true){

        cout << "(Music yang kamu pilih udah ada di Playlist!)" << "\n";

    }

    if (c == 0){

        cout << "Pilihan :" << "\n";
        cout << "1. Next" << "\n";
        cout << "2. Add To Playlist" << "\n";
        cout << "3. Home" << "\n";
        cout << "Masukan Pilihan : ";
        cin >> pilih;

        if (pilih == "1"){

            return next;

        }

        else if (pilih == "2"){

            return add;

        }

        else if (pilih == "3"){

            return home;

        }

        else{

            return ulang;

        }

    }

    else if (c == n-1){

        cout << "1. Back" << "\n";
        cout << "2. Add To Playlist" << "\n";
        cout << "3. Home" << "\n";
        cout << "Masukan Pilihan : ";
        cin >> pilih;

        if (pilih == "1"){

            return back;

        }

        else if (pilih == "2"){

            return add;

        }

        else if (pilih == "3"){

            return home;

        }

        else{

            return ulang;

        }

    }

    else{

        cout << "1. Next" << "\n";
        cout << "2. Back" << "\n";
        cout << "3. Add To Playlist" << "\n";
        cout << "4. Home" << "\n";
        cout << "Masukan Pilihan : ";
        cin >> pilih;

        if (pilih == "1"){

            return next;

        }

        else if (pilih == "2"){

            return back;

        }

        else if (pilih == "3"){

            return add;

        }

        else if (pilih == "4"){

            return home;

        }


        else{

            return ulang;

        }

    }

}

int main(){
	int n=10;
	
	string Judul[n]={"YOU WERE BEAUTIFUL","UNTIL I FOUND YOU","FLY ME TO THE MOON (REMASTERED)","ILYSB-STRIPPED","REMAJA",
					"925","HERE WE GO AGAIN","ENCHANTED","PAPER RINGS","GORGEOUS"};
	string Penyanyi[n]={"DAY6","Stephen Sanchez","Frank Sinatra","LANY","Hivi!","Ardhito Pramono","Ardhito Pramono","Taylor Swift",
						"Taylor Swift","Taylor Swift"};
	string Album[n]={"Sunrise","Until I Found You","FLY ME TO THE MOON (REMASTERED)","LANY","Kereta Kencan","Craziest thing happened in my backyard",
					"Craziest thing happened in my backyard","Speak Now","Lover","Reputation"};
	string rilis[n]={"2016","2021","2008","2017","2017","2020","2020","2010","2019","2017"};
	
    bool exit=false;

	do{

        int pil;
        
        system("cls");  
        header();
        //pilihan
        cout<<"	\t    1. Lihat Lagu \n \t\t    2. Putar Playlist\n \t\t    3. Exit"<<"\n";
        cout<<"-----------------------------------------------------"<<"\n";
        cout<<"	\t    Masukan Pilihan: "; cin>>pil;

        if(pil==1){

            bool returnToHome = false;
            bool ulang= false, notif1 = false;
            int pilih, counter=0;

            do{

                SongList(Judul[counter],Penyanyi[counter],Album[counter],rilis[counter]);
                pilih = Pilih(counter, n, ulang, notif1, notifSongHasAddedToPlaylist);
                if (pilih == 1){

                    counter += 1;
                    ulang = false;
                    notif1 = false;
                    notifSongHasAddedToPlaylist = false;

                }

                else if (pilih == 2){

                    counter -= 1;
                    ulang = false;
                    notif1 = false;
                    notifSongHasAddedToPlaylist = false;

                }

                else if (pilih == 3){

                    // cout << "stack...";
                    //stack.push Judul[counter],Penyanyi[counter]
                    addSong(Judul[counter], Penyanyi[counter]);
                    notif1 = true;

                }

                else if (pilih == 4){

                    returnToHome = true;

                }

                else{

                    ulang = true;
                    notif1 = false;
                    notifSongHasAddedToPlaylist = false;

                }

            }while(returnToHome == false);
        }

        // play playlist song
        else if (pil == 2){
            
            vector<string> song = playlistSong();
            vector<string> artist = playlistArtist();

            if (song.empty() == false){

                Play(song, artist, playlistSize);

            }
            
           
        }

        else if (pil == 3){

            exit = true;
        
        }

    }while(exit == false);

	return 0;
}
