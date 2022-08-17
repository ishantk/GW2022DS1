#include<iostream>
using namespace std;

class Student{

    public:

    int regNumber;
    string name;
    string phone;
    string email;

    Student(){
        regNumber = 0;
        name = "NA";
        phone = "NA";
        email = "NA";
    }

    Student(int regNumber, string name, string phone, string email){
        this->regNumber = regNumber;
        this->name = name;
        this->phone = phone;
        this->email = email;
    }

    void show(){
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"Details of Student: "<<name<<endl;
        cout<<"RegNumber: "<<regNumber<<endl;
        cout<<"Phone: "<<phone<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    }

};

class HashTable{

    int size;             // how many objects are available with HashTable;
    int capacity;         // how many buckets you would have to save data
    // Dynamic Array of Student Pointers :)
    Student** buckets;    // buckets is an array

    public:

    HashTable(): size(0), capacity(13){
       cout<<"HashTable Object Constructed with capacity: "<<capacity<<"..."<<endl;
       initBuckets();
    }

    HashTable(int capacity): size(0), capacity(capacity){
      cout<<"HashTable Object Constructed with capacity: "<<capacity<<"..."<<endl;
      initBuckets();
    }

    int hash(int data){
        int hashCode = data % capacity;
        return hashCode;
    }

    void initBuckets(){
        // create an array of Student Objects dynamically 
        buckets = new Student*[capacity];
        cout<<"buckets is: "<<buckets<<endl;

        // Initialize all the indexes to NULL first..
        for(int idx=0;idx<capacity;idx++){
            buckets[idx] = NULL;
        } 
    }

    void put(int key, Student *student){

        if(size == capacity){
            cout<<"HashTable is Out of Capacity.. No More data can be stored"<<endl;
            return;
        }

        int idx = hash(key);
        cout<<"Storing the Object at idx: "<<idx<<endl;

        if(buckets[idx] == NULL){
            size++;
            buckets[idx] = student;
            cout<<"Student ["<<student<<"] Object "<<key<<" | "<<student->name<<" Added in the HashTable"<<endl;
        }        

    }

    void iterate(){
        for(int idx=0;idx<capacity;idx++){
            if(buckets[idx] != NULL){
                cout<<"Student Object at Index: "<<idx<<endl;
                buckets[idx]->show();
            }
        }
    }

    int tableSize(){
        return size;
    }

    Student* get(int key){
        int idx = hash(key);
        if( (buckets[idx] != NULL) && (key == buckets[idx]->regNumber) ){
            return buckets[idx];
        }else{
            return NULL;
        } 
    }
};

// https://www.cs.usfca.edu/~galles/visualization/ClosedHash.html

int main(){

    HashTable *table = new HashTable(29);
    cout<<"table is: "<<table<<endl;

 
    Student *s1 = new Student(101, "John", "+91 99999 11111", "john@example.com");
    Student *s2 = new Student(13, "Fionna", "+91 99999 22222", "fionna@example.com");
    Student *s3 = new Student(140, "Dave", "+91 99999 33333", "dave@example.com");
    Student *s4 = new Student(71, "Riya", "+91 99999 55555", "riya@example.com");
    
    table->put(s1->regNumber, s1);
    cout<<"Size of Hashtable is: "<<table->tableSize()<<endl;

    table->put(s2->regNumber, s2);
    table->put(s3->regNumber, s3);
    table->put(s4->regNumber, s4);

    // Linear Probing -> Solve the Collisions in HashTable 
    // Wheneever a collision is detected, you search for next available index
    // wherever the next available index is found, you add the element thr :)

    return 0;
}