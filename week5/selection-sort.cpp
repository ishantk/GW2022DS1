#include<iostream>
using namespace std;

// https://visualgo.net/en/sorting
void slectionSort(int* array, int size){
    cout<<"Sorting Array...\n";
    
    // idx < 4 
    // i.e. 
    // idx: 0, 1, 2 and 3
    for(int idx=0; idx<size-1; idx++){

        int minIdx = idx;

        // when, idx: 0
        //       cmpIdx (1) | cmpIdx: 1, 2, 3, 4
        //....
        // Loop will find the index of the minimum element
        for(int cmpIdx=idx+1; cmpIdx<size; cmpIdx++){ 
            if(array[cmpIdx] < array[minIdx]){
                minIdx = cmpIdx;
            }
        }

        int temp = array[idx];
        array[idx] = array[minIdx];
        array[minIdx] = temp;
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
    
    slectionSort(productPrices, 5);

    printArray(productPrices, 5);

    return 0;
}
