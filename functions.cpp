#include<iostream>      // so that you can use cin and cout objects to read and write data
using namespace std;    // use the namespace std

// function: its a piece of code which runs some algorithmic statements to be used again and again
// f(x) = y, where y = x*x + 1
// f(1) -> 1*1 + 1 -> 2
// f(2) -> 2*2 + 1 -> 5

// A function has a name (identifier)
// A funcation have inputs (either no or 1 or many)
// A function can acknowledge back by returning some data

// computeTaxes is a function which perfrom return of data
// returning something from function is kind of acknowledget or output which someone else expects
int computeTaxes(int amount){
    int taxAmount = 20;
    taxAmount += amount;
    return taxAmount; // when we return, function is terminated i.e popped out of memory. this should be the last statement
}

// void is a return type: do not acknowledge or send some data back
// bookCab -> name of function
// typeOfCab -> input
void bookCab(int typeOfCab){
    
    int baseFare = 50;
    // typeOfCab, baseFare are local variable or automatic variables or stack variables

    baseFare += computeTaxes(baseFare);

    if(typeOfCab == 1){ // OLA Mini Cab
        cout<<"OLA MINI CAB BOOKED. Please Pay "<<baseFare<<endl;
    }else if(typeOfCab == 2){ // OLA Sedan Cab
        cout<<"OLA SEDAN CAB BOOKED. Please Pay "<<(baseFare+70)<<endl;
    }else if(typeOfCab == 3){ // OLA Bike Cab
        cout<<"OLA BIKE BOOKED. Please Pay "<<(baseFare-30)<<endl; // 90
    }else{
        cout<<"Please select the cab first"<<endl;
    }

}

// main function: our program in CPP has 1 main function
// its the function which executes when we execute our program
// Execution of Program begins from main
// Whatever we write in main, gets executed in a sequence
int main(){

    // 1. Create Statment
    int age = 30;                   // Create a Single Value Container
    int marks[3] = {90, 80, 70};    // Create a Multu Value Container (Homo) | Array

    // 2. Update Statement
    age += 3;                       // Change the value
    marks[1] += 5;

    // 3. Read Statement
    cout<<"age is: "<<age<<endl;
    cout<<"marks are: "<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<endl;

    // 4. Delete Statement
    // delete keyword is used, BUT for dynamic storage containers
    // in our case containers will be automatically deleted

    bookCab(3);

    cout<<"Thank You For Using My App"<<endl;

    return 0;
}