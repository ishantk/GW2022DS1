#include<iostream>
using namespace std;

class Cab{

    public:
        int baseFare;
        int pricePerKm;

        Cab(): baseFare(50), pricePerKm(6){
            cout<<"Cab Object Constructed"<<endl;
        }

        // VTABLE and VPTR 
        virtual void bookCab(string source, string destination, int distance){
            cout<<"Cab Booked from "<<source<<" to "<<destination<<endl;
            cout<<"Please Pay: \u20b9"<<(baseFare + (distance*pricePerKm))<<endl;
        }
};

// Inheritance -> Parent Child Relationship
// Rules:
// 1. Before the Object of Child, Parent Object is created in memory
// 2. Child can access anything in Parent, if child does not have it other than private
// 3. If child, needs a different version of some function; Child needs to override it
class MiniCab: public Cab{
    public:
        MiniCab(){
            cout<<"MiniCab Object Constructed"<<endl;
        }

        // ReDefined the same function as that of Parent class
        // Overriding
        void bookCab(string source, string destination, int distance){
            pricePerKm += 2;
            cout<<"MiniCab Booked from "<<source<<" to "<<destination<<endl;
            cout<<"Please Pay: \u20b9"<<(baseFare + (distance*pricePerKm))<<endl;
        }
};

class SedanCab: public Cab{
    public:
        SedanCab(){
            cout<<"SedanCab Object Constructed"<<endl;
        }

        // ReDefined the same function as that of Parent class
        // Overriding
        void bookCab(string source, string destination, int distance){
            pricePerKm += 5;
            cout<<"SedanCab Booked from "<<source<<" to "<<destination<<endl;
            cout<<"Please Pay: \u20b9"<<(baseFare + (distance*pricePerKm))<<endl;
        }
};

class Bike: public Cab{
    public:
        Bike(){
            cout<<"Bike Object Constructed"<<endl;
        }

        // ReDefined the same function as that of Parent class
        // Overriding
        void bookCab(string source, string destination, int distance){
            baseFare -= 20;
            pricePerKm -= 3;
            cout<<"Bike Booked from "<<source<<" to "<<destination<<endl;
            cout<<"Please Pay: \u20b9"<<(baseFare + (distance*pricePerKm))<<endl;
        }
};

class OLAApp{

    public:
    Cab* getCab(int option){

        Cab* cab = NULL;

        if(option == 1){
            cab = new MiniCab();
        }else if(option == 2){
            cab = new SedanCab();
        }else if(option == 3){
            cab = new Bike();
        }else{
            cout<<"Invalid Option"<<endl;
        }

        return cab;

    }


};

int main(){

    // MiniCab* cab = new MiniCab();
    // cab->bookCab("Home", "Work", 5);

    // Pointer of Parent can point to the object of Child :)
    // Polymorphic Statement
    //Cab* cab = new MiniCab();
    //cab->bookCab("Home", "Work", 5);

    cout<<"1: Mini Cab"<<endl;
    cout<<"2: Sedan Cab"<<endl;
    cout<<"3: Bike"<<endl;
    cout<<"Enter an Option (1-3): "<<endl;
    int option = 0;
    cin>>option;

    OLAApp app;

    //Cab* cab = OLAApp::getCab(option);
    Cab* cab = app.getCab(option);
    cab->bookCab("Home", "Work", 5);

    return 0;
}
