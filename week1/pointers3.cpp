#include<iostream>
using namespace std;

int main(){

    // age is regular single value container
    int age = 10;

    // ptr is a pointer which holds the adrress of age
    int *ptr = &age;

    // pptr is a pointer to a pointer which holds the address of ptr
    int **pptr = &ptr;

    cout<<"address of age is: "<<&age<<endl;
   
    cout<<"ptr is: "<<ptr<<endl;
    cout<<"address of ptr is: "<<&ptr<<endl;

    cout<<"pptr is: "<<pptr<<endl;
    cout<<"address of pptr is: "<<&pptr<<endl;


    cout<<"*ptr is: "<<*ptr<<endl;
    cout<<"*pptr is: "<<*pptr<<endl;
    cout<<"**pptr is: "<<**pptr<<endl;

    return 0;
}