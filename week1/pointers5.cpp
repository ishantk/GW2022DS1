#include<iostream>
using namespace std;

// Function Returning a Pointer
int* getPrices(){
     int productPrices[5] = {100, 1200, 375, 600, 990};
     // you can return address of an integer
     //return productPrices;
     return &productPrices[0];
}

int main(){

    int* ptr = getPrices();
    
    cout<<"ptr is: "<<ptr<<endl; // ptr now becomes a dangling pointer :)
    cout<<"*ptr is: "<<*ptr<<endl;

    return 0;
}