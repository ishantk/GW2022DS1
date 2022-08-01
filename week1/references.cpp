#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int *ptr = &a;
    
    // b is a reference variable which is an alias name to a
    int &b = a; // give a new name to a as b
    // Here b and a will now be referring to the same memory location

    cout<<"Address of a is: "<<&a<<endl;
    cout<<"Address of b is: "<<&b<<endl;

    // updating b will also update a
    b = 20;
    cout<<"*ptr is: "<<*ptr<<endl;

    return 0;
}