#include<iostream>
using namespace std;

class Duration{

    public:
    
    int hours;
    int mins;

    Duration(): hours(0), mins(0){

    }

    Duration(int hours, int mins): hours(hours), mins(mins){

    }

    void show(){
        cout<<hours<<"h "<<mins<<"m"<<endl;
    }

    bool compareTo(Duration &duration){

        //          2*60    +  40     
        int mins1 = hours*60 + mins;
        //          2*60              + 45
        int mins2 = duration.hours*60 + duration.mins;

        return mins1 > mins2;
    }

    // Operator Overloading
    bool operator>(Duration &duration){

        //          2*60    +  40     
        int mins1 = hours*60 + mins;
        //          2*60              + 45
        int mins2 = duration.hours*60 + duration.mins;

        return mins1 > mins2;
    }

};

int main(){

    Duration duration1(3, 40);
    Duration duration2(4, 45);

    duration1.show();
    duration2.show();

    // int result = duration1.compareTo(duration2);
    // string message = result ? "Duration1 is Greater than Duration2" : "Duration2 is Greater than Duration1";
    // cout<<message<<endl;

    if(duration1 > duration2){ // translated as -> duration1.operator>(duration2)
        cout<<"Duration1 is Greater than Duration2"<<endl;
    }else{
        cout<<"Duration2 is Greater than Duration1"<<endl;
    }

    return 0;
}
