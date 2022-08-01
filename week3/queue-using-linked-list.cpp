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

class PlayListQueue{

    public:
        Song* head;
        Song* tail;
        int size;

        PlayListQueue(): head(NULL), tail(NULL), size(0){
            cout<<"PlayListQueue Created..."<<endl;
        }

        // add the song always in the end i.e. tail :)
        void enqueue(Song* song){ // adds the song in the end
            size++;
            if(head == NULL){
                head = song;
                tail = song;
            }else{
                tail->nextSong = song;
                song->previousSong = tail;
                tail = song;
            }

            // Circular Doubly Linked List
            tail->nextSong = head;
            head->previousSong = tail;

            cout<<"SONG ENQUEUED: "<<song->track<<endl;

        }

        // delete the first song
        void dequeue(){ 

            if(size != 0){
                size--;
                
                Song* previouHead = head;
                head = head->nextSong;
                
                // Circular Doubly Linked List
                tail->nextSong = head;
                head->previousSong = tail;
                
                cout<<"SONG DEQUEUED: "<<previouHead->track<<endl;
                delete previouHead; // now delete the previous head

            }else{
                cerr<<"No Song Available to Delete"<<endl;
            }
        }

        Song* peekFront(){
            return head;
        }

        Song* peekBack(){
            return tail;
        }
};

int main(){

    Song *song1 = new Song("1. Kesariya", "Pritam, Arijit Singh", 4.28);
    Song *song2 = new Song("2. Peaches", "Diljit Dosanjh", 3.10);
    Song *song3 = new Song("3. Left and Right", "Charlie Puth, Jung Kook", 2.34);    
    Song *song4 = new Song("4. Dhoke Pyaar Ke", "Rochak Kohli, B Praak", 4.19);  
    Song *song5 = new Song("5. Fitoor", "R-Nait, Gurlez Akhtar", 4.36);

    // FIFO : First In and First Out :)
    PlayListQueue* queue = new PlayListQueue();
    cout<<"Initial Size of PlayListQueue is: "<<queue->size<<endl;
    
    queue->enqueue(song1);
    queue->enqueue(song2);
    queue->enqueue(song3);
    queue->enqueue(song4);
    queue->enqueue(song5);

    queue->dequeue();
    
    queue->peekFront()->showSong();
    queue->peekBack()->showSong();

    cout<<"Size of PlayListQueue now is: "<<queue->size<<endl;

    return 0;
}
