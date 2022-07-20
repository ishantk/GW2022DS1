#include<iostream>
using namespace std;

int main(){

    int age = 10;
    
    cout<<"age is: "<<age<<endl;
    cout<<"address of age is: "<<&age<<endl;

    // pointer holds Address of some variable
    // it can always hold address where the data type must be same
    int* ptr;
    ptr = &age;

    // show the contents of ptr variable
    cout<<"ptr is: "<<ptr<<endl;  // address            
    // show the adress of pointer variable
    cout<<"address of ptr is: "<<&ptr<<endl;

    // De Reference your Pointer
    cout<<"*ptr is: "<<*ptr<<endl;     // value at the address which ptr is holding

    return 0;
}