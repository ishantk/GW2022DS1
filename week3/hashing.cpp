#include<iostream>
using namespace std;

class HashSet{

    public:

        // how much buckets do we have to save data
        int capacity; // number of buckets 

        // how many elements do we have in the data structure
        int size;

        // Create an Array of Buckets
        int* buckets;

        HashSet(){
            capacity = 8;
            size = 0;
            
            // create an integer array dynamically 
            buckets = new int(capacity);

            // Initialize all the indexes to 0 first..
            for(int idx=0;idx<capacity;idx++){
                buckets[idx]=0;
            }
            
            cout<<"HashSet Created..."<<endl;
        }

        int hash(int data){
            int hashCode = data % capacity;
            return hashCode;
        }

        void add(int data){

            int hashCode = hash(data);
            
            if(buckets[hashCode] == 0){
                size++;
                buckets[hashCode] = data;
                cout<<data<<" added at idx: "<<hashCode<<endl;
            }else{
                cout<<"Sorry. Data at Bucket "<<hashCode<<" Exists..."<<endl;
            }

        }

        void iterate(){
            cout<<"Iterating in HashSet..."<<endl;
            for(int idx=0;idx<capacity;idx++){
                if(buckets[idx] !=0){
                    cout<<"buckets["<<idx<<"] is: "<<buckets[idx]<<endl;
                }
            }
        }
};

int main(){
    
    HashSet* set = new HashSet();
    cout<<"Initial Size of HashSet is: "<<set->size<<endl;
    set->iterate();

    set->add(10);
    set->add(12);
    set->add(21);
    set->add(33);
    set->add(17);

    cout<<"Finally Size of HashSet is: "<<set->size<<endl;
    set->iterate();

    return 0;
}

// Features:
// 1. Unique
// 2. UnOrdered Output as Iteration
// 3. Searched in O(1)