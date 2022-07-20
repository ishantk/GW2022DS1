#include<iostream>
using namespace std;

int main(){

    int a = 10;         // a is a variable, which can be modified
    const int b = 20;   // b is a constant, which cannot be modified

    // Regular Pointer
    int *ptr = &a;

    // Pointer to a Constant
    const int* ptrToConstant = &b;
    // we cannot modify value of b
    //*cptr = 200; // error

    // Constant Pointer
    int* const constantPtr = &a;
    int c = 10;
    //constantPtr = &c;  // error

    *constantPtr = 333; // we can change the contents in a

    // Constant Pointer Pointing to a Constant
    const int* const cptr = &b;
    // here we cannot change address or value: Strict Read Only Operation

    return 0;
}