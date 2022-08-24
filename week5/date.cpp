#include<iostream>
using namespace std;

// Implement Operator Overloading and compare 2 date and 2 time objects

class Date{

    public:
        int dd;
        int mm;
        int yy;

    Date(){

    }  

    Date(int dd, int mm, int yy): dd(dd), mm(mm), yy(yy){
        
    } 

    bool operator>(Date& date){

        return true;
    } 

    bool operator<(Date& date){
        
        return true;
    }    
};

class Time{

    public:
        int hh;
        int mm;
        int ss;
    
    Time(){

    }  

    Time(int hh, int mm, int ss): hh(hh), mm(mm), ss(ss){
        
    }   

    bool operator>(Time& time){
        
        return true;
    } 

    bool operator<(Time& time){
        
        return true;
    } 
};

int main(){

    Date d1(25, 8, 2022);
    Date d2(27, 8, 2022);

    Time t1(10, 5, 44);
    Time t2(11, 12, 30);

    if(d1 > d2){

    }else{

    }

    if(t1 > t2){

    }else{

    }

    return 0;
}
