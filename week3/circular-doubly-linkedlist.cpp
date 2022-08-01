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

class PlayList{

    public:
        Song* head;
        Song* tail;
        int size;

        PlayList(): head(NULL), tail(NULL), size(0){

        }

        void add(Song* song){ // adds the song in the end
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

            cout<<"Head: "<<head<<" Tail: "<<tail<<endl;
            song->showSong();
            cout<<endl;
        }

        void iterate(int direction=0){
            if(direction == 0){
                cout<<"```````````````````````````"<<endl;
                cout<<"ITERATING FORWARD"<<endl<<endl;
                cout<<"```````````````````````````"<<endl;
                Song* temp = head;
                while(true){
                    temp->showSong();
                    temp = temp->nextSong;
                    if(temp == head){
                        break;
                    }
                }
            }else{
                cout<<"```````````````````````````"<<endl;
                cout<<"ITERATING BACKWARD"<<endl<<endl;
                cout<<"```````````````````````````"<<endl;
                Song* temp = tail;
                while(true){
                    temp->showSong();
                    temp = temp->previousSong;
                    if(temp == tail){
                        break;
                    }
                }
            }
        }

        void deleteHead(){ // delete the first song

            if(size != 0){
                size--;
                
                Song* previouHead = head;
                head = head->nextSong;
                
                // Circular Doubly Linked List
                tail->nextSong = head;
                head->previousSong = tail;
                
                delete previouHead; // now delete the previous head
            }else{
                cerr<<"No Song Available to Delete"<<endl;
            }
        }

        // Implement 4 methods, keeping in mind the edge cases :)
        void deleteTail(){
            size--;
            // Code : Assignment
        }

        void insert(Song* song){ // insert in the beginning :)
            // Code : Assignment
            size++;
        }

        void insertInBetween(Song* song1, Song* song2, Song* song){
            size++;
            // Code : Assignment
        }

        void deleteInBetween(Song* song1, Song* song2){
            size--;
            // Code : Assignment
        }

};

int main(){

    Song *song1 = new Song("1. Kesariya", "Pritam, Arijit Singh", 4.28);
    Song *song2 = new Song("2. Peaches", "Diljit Dosanjh", 3.10);
    Song *song3 = new Song("3. Left and Right", "Charlie Puth, Jung Kook", 2.34);    
    Song *song4 = new Song("4. Dhoke Pyaar Ke", "Rochak Kohli, B Praak", 4.19);  
    Song *song5 = new Song("5. Fitoor", "R-Nait, Gurlez Akhtar", 4.36);

    PlayList* list = new PlayList();
    list->add(song1);
    list->add(song2);
    list->add(song3);
    list->add(song4);
    list->add(song5);

    list->deleteHead();

    cout<<"Size of PlayList is: "<<list->size<<endl;

    list->iterate();
    
    //list->iterate(1);
    
    return 0;
}
