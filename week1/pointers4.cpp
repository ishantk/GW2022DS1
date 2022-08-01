#include<iostream>
using namespace std;

int main(){

    // price is a single value container
    int price = 10;

    // productPrices is an array i.e. a multi value container
    //                       0     1    2    3    4
    int productPrices[5] = {100, 1200, 375, 600, 990};

    cout<<"price is: "<<price<<endl;
    
    // productPrices is printing the address of 1st element in array
    cout<<"productPrices is: "<<productPrices<<endl;
    cout<<"Address of productPrices[0] is: "<<&productPrices[0]<<endl;
    cout<<"Address of productPrices[1] is: "<<&productPrices[1]<<endl;
    cout<<"Address of productPrices[2] is: "<<&productPrices[2]<<endl;

    // De Reference array to get the data at the address with * oeprator
    cout<<*productPrices<<endl;

    // Copy the address of 1st element of productPrices array into ptr
    int* ptr = productPrices;
    //int* ptr = &productPrices[0];

    for(int i=0; i<5; i++){
        cout<<ptr<<endl;
        cout<<*ptr<<endl;
        ptr++; // increment ptr by 1 means, increment to next memory location
    }

    cout<<"Iterating in product prices"<<endl;

    for(int i=0;i<5;i++){
        cout<<*(productPrices+i)<<endl;
    }

    return 0;
}

// Pointers can be used with arrays to indirectly access them
// Assignment: Explore **pptr with 2D Arrays