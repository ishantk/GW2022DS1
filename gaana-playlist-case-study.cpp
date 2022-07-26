#include<iostream>
using namespace std;

class Song{

    public:
        string track;
        string artists;
        float duration;

        Song *nextSong;
        Song *previousSong;

        Song(): track("NA"), artists("NA"), duration(0.0){

        }

        Song(string track, string artists, float duration): track(track), artists(artists), duration(duration){

        }

        void showSong(){
            cout<<"----------------------------------------------"<<endl;
            cout<<track<<"["<<duration<<"]"<<endl;
            cout<<artists<<endl;
            cout<<"----------------------------------------------"<<endl;
        }

};

void iterate(Song* start, Song* end, int type){

    if(type == 1){
        while(true){
            start->showSong();
            start = start->nextSong;

            if(start->nextSong == end){
                break;
            }
        }
        start->showSong();
    }else{
        while(true){
            start->showSong();
            start = start->previousSong;

            if(start->previousSong == end){
                break;
            }
        }
        start->showSong();
    }

}


int main(){
    
    Song *song1 = new Song("Kesariya", "Pritam, Arijit Singh", 4.28);
    Song *song2 = new Song("Peaches", "Diljit Dosanjh", 3.10);
    Song *song3 = new Song("Left and Right", "Charlie Puth, Jung Kook", 2.34);    
    Song *song4 = new Song("Dhoke Pyaar Ke", "Rochak Kohli, B Praak", 4.19);  
    Song *song5 = new Song("Fitoor", "R-Nait, Gurlez Akhtar", 4.36);

    //song1->showSong();
    
    cout<<"song1 is: "<<song1<<endl;
    cout<<"song2 is: "<<song2<<endl;
    cout<<"song3 is: "<<song3<<endl;
    cout<<"song4 is: "<<song4<<endl;
    cout<<"song5 is: "<<song5<<endl;

    // Copy the Address
    song1->nextSong = song2;
    song2->nextSong = song3;
    song3->nextSong = song4;
    song4->nextSong = song5;
    song5->nextSong = song1;

    song1->previousSong = song5;
    song2->previousSong = song1;
    song3->previousSong = song2;
    song4->previousSong = song3;
    song5->previousSong = song4;


    // Iterate Forward Direction
    // Song* temp = song1;

    // while(true){
    //     temp->showSong();
    //     temp = temp->nextSong;

    //     if(temp->nextSong == song1){
    //         break;
    //     }
    // }
    // temp->showSong();

    // cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;

    // temp = song5;
    // while(true){
    //     temp->showSong();
    //     temp = temp->previousSong;

    //     if(temp->previousSong == song5){
    //         break;
    //     }
    // }
    // temp->showSong();

    iterate(song5, song5, 1);
    
    return 0;
}

// Assignment 1: 
// Try to work with recursion to iterate in forward and backward direction

// Assignment 2:
// Use the same approach like the code above and create a LinkedList of Chat Conversation
// Remeber the Chat Conversations they do not last object pointing to the first and vice versa

