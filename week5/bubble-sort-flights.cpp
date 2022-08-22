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

    /*int compareTo(Duration& duration){
        // implement this method
    }*/

    int operator>(Duration& duration){
        // implement the operator function
        // compare hours and mins one one duration object to the other duration object
    }

};

class Flight{

    public:

    string departureLocation;
    Duration* departureTime;

    string arrivalLocation;
    Duration* arrivalTime;

    string flightName;

    Duration* duration;

    Flight(){

    }

    Flight(string departureLocation, Duration* departureTime, string arrivalLocation, Duration* arrivalTime, string flightName, Duration* duration){
        this->departureLocation = departureLocation;
        this->departureTime = departureTime;
        this->arrivalLocation = arrivalLocation;
        this->arrivalTime = arrivalTime;
        this->flightName = flightName;
        this->duration = duration;
    }

    void showFlight(){
        // Show the Flight Object
    }
};

void listFlights(Flight* flights, int size){

}

void filterFlightsDurationLowToHight(Flight* flights, int size){

}

void filterFlightsDurationHighToLow(Flight* flights, int size){

}

void filterFlightsPriceLowToHight(Flight* flights, int size){

}

void filterFlightsPriceHighToLow(Flight* flights, int size){

}


int main(){

    Flight flight1("Delhi", new Duration(8, 20), "Bengaluru", new Duration(10, 40), "Air Asia", new Duration(2, 30));
    Flight flight2("Delhi", new Duration(11, 20), "Bengaluru", new Duration(12, 40), "Indigo", new Duration(2, 50));
    Flight flight3("Delhi", new Duration(13, 55), "Bengaluru", new Duration(15, 35), "Air India", new Duration(3, 10));
    Flight flight4("Delhi", new Duration(12, 30), "Bengaluru", new Duration(14, 20), "SpiceJet", new Duration(2, 10));
    Flight flight5("Delhi", new Duration(9, 15), "Bengaluru", new Duration(10, 40), "indigo", new Duration(1, 5));


    Flight flights[] = {flight1, flight2, flight3, flight4, flight5};
    

    return 0;
}