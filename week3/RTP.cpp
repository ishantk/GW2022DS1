#include<iostream>
using namespace std;

class Song{

    public:
        string track;
        string artists;
        float duration;

        Song *next;
        Song *previous;

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
            cout<<"song: "<<this<<" next: "<<next<<" previous: "<<previous<<endl;
            cout<<"----------------------------------------------"<<endl;
        }

};


class LinkedList{
    
    public:
    
        Song* head;
        Song* tail;
        int size;

        LinkedList(): head(NULL), tail(NULL), size(0){
            cout<<"LinkedList Created..."<<endl;
        }

        // adds the song in the end
        // add serves 3 purposes
        // 1. adds the data for LinkedList
        // 2. adds the data for Queue and serves as enqueue
        // 3. adds the data for Stack and serves as push
        void add(Song* song){ 
            size++;
            if(head == NULL){
                head = song;
                tail = song;
            }else{
                tail->next = song;
                song->previous = tail;
                tail = song;
            }

            // Circular Doubly Linked List
            tail->next = head;
            head->previous= tail;

            cout<<"Head: "<<head<<" Tail: "<<tail<<endl;
            song->showSong();
            cout<<endl;
        }

        // Remove removes the head of List
        // 1. It solves the purpose of dequeue i.e. FIFO Principle :)
        // 2. It can be used to delete the first element
        void removeFirst(){ 

            if(size != 0){
                size--;
                
                Song* previousHead = head;
                head = head->next;
                
                // Circular Doubly Linked List
                tail->next = head;
                head->previous = tail;
                
                delete previousHead; // now delete the previous head
            }else{
                cerr<<"No Song Available to Delete"<<endl;
            }
        }

        // Remove removes the tail of List
        // 1. It solves the purpose of pop i.e. LIFO Principle :)
        // 2. It can be used to delete the last element
        void removeLast(){ 

            if(size != 0){
                size--;
                
                Song* previousTail = tail;
                tail = tail->previous;
                
                // Circular Doubly Linked List
                tail->next = head;
                head->previous = tail;
                
                delete previousTail; // now delete the previous tail
            }else{
                cerr<<"No Song Available to Delete"<<endl;
            }
        }


};

class Stack : public LinkedList{
    
    public:
    Stack(){
        cout<<"Stack Created..."<<endl;
    }

    void pop(){ 
        if(size != 0){
            size--;
                
            Song* previousTail = tail;
            tail = tail->previous;
                
            // Circular Doubly Linked List
            tail->next = head;
            head->previous = tail;
                
            delete previousTail; // now delete the previous tail
        }else{
            cerr<<"No Song Available to Delete"<<endl;
        }        
    }
};

class Queue : public LinkedList{
    
    public:
    Queue(){
        cout<<"Queue Created..."<<endl;
    }

    void dequeue(){ 

        if(size != 0){
            size--;
                
            Song* previousHead = head;
            head = head->next;
                
            // Circular Doubly Linked List
            tail->next = head;
            head->previous = tail;
                
            delete previousHead; // now delete the previous head
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

// Hierarchy. Same Parent (LinkedList) -> multiple Children (Stack and Queue)
class DataStructure{

    public:

    static LinkedList* getDataStructure(int option){

        LinkedList* object;

        if(option == 1){
            object = new LinkedList();
        }else if(option == 2){
            object = new Stack();
        }else if(option == 3){
            object = new Queue();
        }else{
            object = NULL;
        }

        return object;
    }

};

int main(){

    cout<<"1: LinkedList"<<endl;
    cout<<"2: Stack"<<endl;
    cout<<"3: Queue"<<endl;
    cout<<"Enter an Option (1-3): "<<endl;
    int option = 0;
    cin>>option;
    
    LinkedList* object = DataStructure::getDataStructure(option);
    // object now dynamically can be either LinkedList or Stack or Queue :)

    Song *song1 = new Song("1. Kesariya", "Pritam, Arijit Singh", 4.28);
    Song *song2 = new Song("2. Peaches", "Diljit Dosanjh", 3.10);
    Song *song3 = new Song("3. Left and Right", "Charlie Puth, Jung Kook", 2.34);    
    Song *song4 = new Song("4. Dhoke Pyaar Ke", "Rochak Kohli, B Praak", 4.19);  
    Song *song5 = new Song("5. Fitoor", "R-Nait, Gurlez Akhtar", 4.36);

    object->add(song1);
    object->add(song2);
    object->add(song3);
    object->add(song4);
    object->add(song5);

    object->removeFirst();
    object->removeFirst();

    object->head->showSong();

    Queue* queue = new Queue();

    queue->add(song1);
    queue->add(song2);
    queue->add(song3);
    queue->add(song4);
    queue->add(song5);

    queue->dequeue();
    queue->dequeue();
    queue->dequeue();

    queue->peekFront()->showSong();

    return 0;
}
