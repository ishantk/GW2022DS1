#include<iostream>
using namespace std;

int main(){

    int age = 10;
    int *ptr = &age;    // ptr contains the address of age

    // Pointers can only point to the same type
    char ch = 'A';
    char *cptr = &ch;

    int amount = 100;   
    ptr = &amount; // update the ptr now, with address of amount
    *ptr = 120; // value at ptr(address of amount) -> update amount to 120

    cout<<"age is: "<<age<<endl; // 10
    cout<<"ptr is: "<<ptr<<endl; // address of amount
    cout<<"*ptr is: "<<*ptr<<endl; // 120
    cout<<"amount is: "<<amount<<endl; // 120

    return 0;
}

// Pointer: its a variable holding the address of other variable. indirect access to the variable 