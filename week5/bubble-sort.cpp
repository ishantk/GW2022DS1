/*
    Sorting Techniques
    Arrange data in ordered way :)
    To arrange data in an array or some data structure either in ascending or descending arrangement

    Why ?
    1. To find the element with lesser time
    2. first element will be min, last max :)
    3. Sorting is a great filter. On ecommerce platform, we can filter price low to high to vice versa

    We will majorly see sorting on Objects in industrial use cases...

    WhatsApp and Sorting ?
    Messages in WhatsApp are sorted based on dateTimeStamp :)
    
    ContactsApp contacts sorted as per characters i.e. alphabetically :)
*/

#include<iostream>
using namespace std;

// https://visualgo.net/en/sorting
void bubbleSort(int* array, int size){
    cout<<"Sorting Array...\n";
    
    // idx < 4 
    // i.e. 
    // idx: 0, 1, 2 and 3
    for(int idx=0; idx<size-1; idx++){

        // when, idx: 0
        //       cmpIdx (5-0-1 => 4) | cmpIdx: 0, 1, 2, 3
        // when, idx: 1
        //       cmpIdx (5-1-1 => 3) | cmpIdx: 0, 1, 2
        // when, idx: 2
        //       cmpIdx (5-2-1 => 2) | cmpIdx: 0, 1
        // when, idx: 3
        //       cmpIdx (5-3-1 => 1) | cmpIdx: 0
        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(array[cmpIdx] > array[cmpIdx+1]){
                // swap the values i.e. elements of array :)
                int temp = array[cmpIdx];
                array[cmpIdx] = array[cmpIdx+1];
                array[cmpIdx+1] = temp;
            }
        }
    }

    cout<<endl<<endl;
}

void printArray(int* array, int size){
    cout<<"Printing Array...\n";
    
    for(int idx=0; idx<size; idx++){
        cout<<array[idx]<<" ";
    }
    
    cout<<endl<<endl;
}

int main(){
    //                      0      1    2     3     4
    int productPrices[] = {1200, 1100, 3500, 1900, 500};
    printArray(productPrices, 5);
    
    bubbleSort(productPrices, 5);

    printArray(productPrices, 5);

    return 0;
}
