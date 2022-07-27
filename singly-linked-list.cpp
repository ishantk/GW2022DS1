#include<iostream>
using namespace std;

class Node{ // node represents an object
    // We have Just integer data in our Node Object
    public:
        int data;       // integer data
        Node* nextNode; // Points to the next node

        Node(): data(0), nextNode(NULL){

        }

        Node(int data): data(data), nextNode(NULL){
        
        }

        void show(){
            cout<<"data is: "<<data<<endl;
        }
};

class LinkedList{

    public:
        
        Node* head; // head will point to the first object in the LinkedList
        Node* tail; // tail will point to the last object in the LinkedList

        int size;

        LinkedList(): head(NULL), tail(NULL), size(0){
            cout<<"[LinkedList] Created"<<endl;
            cout<<"[LinkedList] head: "<<head<<" tail: "<<tail<<" size: "<<size<<endl;
        }

        // To add the data
        void add(int data){

            size++;

            Node* node = new Node(data);
            cout<<"[LinkedList] [add] node is: "<<node<<" size: "<<size<<endl;

            if(head == NULL){
                head = node;
                tail = node;
                cout<<"[LinkedList] [add] [if] head: "<<head<<" tail: "<<tail<<" size: "<<size<<endl;
            }else{
                tail->nextNode = node;
                tail = node;
                cout<<"[LinkedList] [add] [else] head: "<<head<<" tail: "<<tail<<" size: "<<size<<endl;
            }

            cout<<"[LinkedList] [add] node's "<<node<<" next node is: "<<node->nextNode<<endl;

    }

    void iterate(){

        Node* temp = head;
        while(true){

            temp->show();
            temp = temp->nextNode;

            if(temp == NULL){
                break;
            }

        }
    }

    int getSize(){
        return size;
    }

    bool contains(int data){

        Node* temp = head;
        while(true){

            if(temp->data == data){
                return true;
            }

            temp = temp->nextNode;

            if(temp == NULL){
                break;
            }
        }

        return false;
    }

    void deleteFirst(){
        Node* temp = head;
        cout<<"[deleteFirst] Deleting node "<<head->data<<endl;

        // update the head
        head = head->nextNode;
        
        // delete the node
        delete temp; // remove the object from the heap  :)
        size--;
        cout<<"[deleteFirst] Node Deleted."<<endl;
    }

    void deleteLast(){

        Node* temp = head;
        cout<<"[deleteLast] Deleting node "<<tail->data<<endl;

        while(temp->nextNode->nextNode != NULL){
            temp = temp->nextNode;
        }

        // Here, outside the loop, temp has the address of the second last node :)
        Node* toDelete = tail;
        temp->nextNode = NULL;
        tail = temp;
        size--;
        delete toDelete;
        cout<<"[deleteLast] Node Deleted."<<endl;
    }

    void deleteData(int data){
        // assignmet :)
    }

};

int main(){

    cout<<"[main] started"<<endl;

    // Dynamic LinkedList Object :)
    LinkedList* list = new LinkedList();
    cout<<"[main] list is: "<<list<<endl;

    list->add(10);
    list->add(20);
    list->add(15);
    list->add(40);
    list->add(35);

    list->iterate();

    cout<<"Size of List is: "<<list->getSize()<<endl;
    cout<<"Is 15 in the List ?: "<<list->contains(75)<<endl;

    cout<<"~~~~~~~~~~~~"<<endl;

    list->deleteFirst();
    list->deleteLast();
    list->deleteData(15);
    cout<<"Size of List is: "<<list->getSize()<<endl;
    list->iterate();

    cout<<"[main] finished"<<endl;

    return 0;
}