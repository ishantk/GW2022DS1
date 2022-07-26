#include<iostream>
using namespace std;

int square(int number){
    return number*number; // 25
}

        //    10         5
void add(int num1, int num2){

    cout<<"[add] started"<<endl;

    num1 = square(num2);

    int sum = num1 + num2; // 25 + 5
    cout<<"[add] sum is: "<<sum<<endl;

    cout<<"[add] ended"<<endl;
}

/*int main(){
    cout<<"[main] started"<<endl;
    int age = 10; // storage container in memory

    add(age, 5);

    cout<<"[main] ended"<<endl;
    return 0;
}*/

void print(int number){
    cout<<"number is: "<<number<<endl;
    number++;
    if(number <=10){
        print(number); // Function print calls itself again and again
    }
}


int main(){
    cout<<"[main] started"<<endl;

    /*for(int idx=1;idx<=10;idx++){
        cout<<"idx is: "<<idx<<endl;
    }*/

    print(1);

    cout<<"[main] ended"<<endl;
    return 0;
}