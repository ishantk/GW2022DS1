#include<iostream>
using namespace std;

int getMax(int *ptr, int length){
    
    int max = *ptr; // 100 is assumed to be max
    ptr++; // take the pointer to next address i.e. 1st index address
    for(int i=1;i<length;i++){
        if(*ptr > max){
            max = *ptr;
        }
        ptr++;
    }

    return max;
}

int main(){

    int productPrices[5] = {100, 1200, 375, 1600, 990};
    //int result = getMax(productPrices, 5);
    int result = getMax(&productPrices[0], 5);

    cout<<"result is: "<<result<<endl;

    return 0;
}