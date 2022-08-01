#include<iostream>
using namespace std;

int max(int array[], int length){

    // Base Case for the Problem :)
    // in case array has only 1 element, it will be ofcouse the maximum
    if(length == 1){
        return array[0];
    }else{
        int num = max(array, length-1); // call the same function again by reducing the length by 1
        // we will get back num as 10, when the length is 2 :)
        if(num > array[length-1]){
            return num;
        }else{
            return array[length-1];
        }
    }

    return 0;
}


int main(){
    cout<<"[main] started"<<endl;

    // Find the max in this array
    // Using Recursion
    int numbers[3] = {10, 20, 30};

    int result = max(numbers, 3);
    cout<<"[main] result: "<<result<<endl;

    cout<<"[main] ended"<<endl;
    return 0;
}