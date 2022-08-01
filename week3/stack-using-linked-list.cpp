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

        ~Song(){
            cout<<"Song Deleted: "<<track<<endl;
        }

        void showSong(){
            cout<<"----------------------------------------------"<<endl;
            cout<<track<<"["<<duration<<"]"<<endl;
            cout<<artists<<endl;
            cout<<"song: "<<this<<" next: "<<nextSong<<" previous: "<<previousSong<<endl;
            cout<<"----------------------------------------------"<<endl;
        }

};

class PlayListStack{

    public:
        Song* head;
        Song* tail;
        int size;

        PlayListStack(): head(NULL), tail(NULL), size(0){
            cout<<"PlayListStack Created..."<<endl;
        }

        // add the song always in the head :)
        // i.e. insert in the beginnig
        void push(Song* song){
            size++;
            if(head == NULL){
                head = song;
                tail = song;
            }else{
                head->nextSong = song;
                song->previousSong = head;
                head = song;
            }

            cout<<"SONG PUSHED: "<<song->track<<endl;
        }

        // remove the last added song :)
        void pop(){ 

            if(size != 0){
                size--;
                
                Song* previouHead = head;
                head = head->previousSong;
                head->nextSong = NULL;

                delete previouHead; // now delete the previous head

            }else{
                cerr<<"No Song Available to Delete"<<endl;
            }
        }

        Song* peek(){
            return head;
        }
};

int main(){

    Song *song1 = new Song("1. Kesariya", "Pritam, Arijit Singh", 4.28);
    Song *song2 = new Song("2. Peaches", "Diljit Dosanjh", 3.10);
    Song *song3 = new Song("3. Left and Right", "Charlie Puth, Jung Kook", 2.34);    
    Song *song4 = new Song("4. Dhoke Pyaar Ke", "Rochak Kohli, B Praak", 4.19);  
    Song *song5 = new Song("5. Fitoor", "R-Nait, Gurlez Akhtar", 4.36);

    PlayListStack* stack = new PlayListStack();
    cout<<"Initial Size of PlayListStack is: "<<stack->size<<endl;
    
    stack->push(song1);
    stack->push(song2);
    stack->push(song3);
    stack->push(song4);
    stack->push(song5);

    // Remove the Last Added Object in the Stack | LIFO
    stack->pop();
    
    stack->peek()->showSong();
    cout<<"Size of PlayListStack now is: "<<stack->size<<endl;

    return 0;
}
