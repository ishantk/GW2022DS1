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

    // We divided our put function in 2 parts so as to implement recursion with ease
    // See how you can just implement the algorithm in 1 single put function itself.

    void put(int key, Student *student){

        int idx = hash(key);

        if(buckets[idx] == NULL){
            size++;
            buckets[idx] = student;
            cout<<"Student ["<<student<<"] Object "<<key<<" | "<<student->name<<" Added in the HashTable at idx: "<<idx<<endl;
        }else{
            // We detected a collision...
            idx++;
            if(idx >= capacity && size<capacity){
                idx = 0;
                put(key, student, idx);
            }else{
                if(size < capacity){
                    put(key, student, idx);
                }else{
                    cout<<"No More Bucket Available to Store the Student. HashTable Overflown.."<<endl;
                }
            }
        }      
    }

    void put(int key, Student *student, int idx){
        
        if(buckets[idx] == NULL){
            size++;
            buckets[idx] = student;
            cout<<"Student ["<<student<<"] Object "<<key<<" | "<<student->name<<" Added in the HashTable at idx: "<<idx<<endl;        }else{
            // We detected a collision...
            idx++;
            if(idx >= capacity && size<capacity){
                idx = 0;
                put(key, student, idx);
            }else{
                if(size < capacity){
                    put(key, student, idx);
                }else{
                    cout<<"No More Bucket Available to Store the Student. HashTable Overflown.."<<endl;
                }
            }
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

    void remove(int key){
        // Implement the remove Function which uses linear probing
    }

    int* keys(){
        // Return Array of all the Keys in the HashTable
    }

    Student* get(int key){
      // Implement the get Function which uses linear probing
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
    Student *s5 = new Student(28, "Ken", "+91 99999 66666", "ken@example.com");
    Student *s6 = new Student(29, "Leo", "+91 99999 77777", "leo@example.com");
    Student *s7 = new Student(57, "Mike", "+91 99999 88888", "mike@example.com");
    
    table->put(s1->regNumber, s1);
    //cout<<"Size of Hashtable is: "<<table->tableSize()<<endl;

    table->put(s2->regNumber, s2);
    table->put(s3->regNumber, s3);
    table->put(s4->regNumber, s4);
    table->put(s5->regNumber, s5);
    table->put(s6->regNumber, s6);
    table->put(s7->regNumber, s7);

    // Linear Probing -> Solve the Collisions in HashTable 
    // Wheneever a collision is detected, you search for next available index
    // wherever the next available index is found, you add the element thr :)

    return 0;
}

// Assignment:
// Implement Quadratic Probing..