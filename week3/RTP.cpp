#include<iostream>
using namespace std;

class LinkedList{
    
    public:
    LinkedList(){
        cout<<"LinkedList Created..."<<endl;
    }
};

class Stack : public LinkedList{
    
    public:
    Stack(){
        cout<<"Stack Created..."<<endl;
    }
};

class Queue : public LinkedList{
    
    public:
    Queue(){
        cout<<"Queue Created..."<<endl;
    }
};

// Hierarchy. Same Parent (LinkedList) -> multiple Children (Stack and Queue)
class DataStructures{

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

class CA{

};

class CB : public CA{

};

int main(){

    cout<<"1: LinkedList"<<endl;
    cout<<"2: Stack"<<endl;
    cout<<"3: Queue"<<endl;
    cout<<"Enter an Option (1-3): "<<endl;
    int option = 0;
    cin>>option;
    
    LinkedList* object = DataStructures::getDataStructure(option);

    // Parent Class pointer can point to the object of Child :)
    CA* ptr = new CB();

    return 0;
}
