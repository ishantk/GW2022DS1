/*
    OOPS
        1. Object
            Real World: Object is anything which exists in reality
                        objects have attributes -> height, weight
            Computer Scince: Object is a Storage Container
                             (Homo/Hetro) -> MULTI VALUE CONTAINER
                             the data which object will hold
                             has key value pair kind of notation
                             where key is the attribute name, and value is the data
        2. Class
            Real World: Representation of the Object
                        Drawing(BluePrint) of an object
            Computer Scince: A program which defines the structure of object (how an object will be in the memory)
                             it is created using the class keyword

        What will you think of first ? Object or Class ?

        Principle Of OOPS:
        1. Think of an Object
            You need to study requirements, posted by client to develop a SW
            Pick up the terms, which would have lot of data associated to it

            On Zomato
            Restaurant (name, phone, email, operatingHours, reviews)
            Dish (name, price, ratings, description, imageURL)
            User (name, phone, email, gender)
            Address(adrsLine, city, state, zipCode, label, latitude, longitude)
            Order (oid, amount, user, dishes)

            Objects are related to each other
            1 User has 1 Address
            1 User has many Addresses
            1 Restaurant has Many Dishes
            Many Users places many Orders

            On WhatsApp
            Contact (name, phone, image)
            Conversation (text, sender, receiver)
            .
            ....

            On MMT
            FlightBooking (from, to, departureDate, numOftravellers, travelClass)

            On PayTM
            MobileRecharge (phoneNumber, operator, circle, amount) 

        2. Create its Class
        3. From the Class Create the real object in memory
            3.1 Static Object Construction -> happens at the compile time
            3.2 Dynamic Object Construction -> happens at the run time

*/

#include<iostream>
using namespace std;

// 1. Think of an Object
//    Dish (name, price, ratings)

// 2. Create its class
class Dish{ // class Dish is representing the structure of Dish Object

    // Whatever you code in class, belongs to OBJECT :)

    // by default everything in class is private
    
    // below this public: data members and member functions will have a public access
    public:
    // Attributes or Data members or instance variables
    string name;
    int price;
    float ratings;
    
    // Functions or Methods or Procedures or memeber functions

    // Constructor: Default Constructor
    /*Dish(){
        name = "NA";
        price = 0;
        ratings = 1.5;
    }*/

    Dish(): name("NA"), price(0), ratings(1.5){
 
    }

    // Constructor: Parameterized Constructor
    Dish(string name, int price, float ratings): name(name), price(price), ratings(ratings){
 
    }

    // Function
    void showDish(){
        cout<<"Dish is: "<<name<<" \u20b9"<<price<<" "<<ratings<<endl;
    }

};

int main(){

    // dish1 is an object which gets created in the frame of main function
    // object is given the memory by the compiler at the time of compilation
    Dish dish1; // execute default constructor
    Dish dish2("Noodles", 100, 3.5); // execute parametrized constructor
    
    // Reference Variable dish3 for dish1
    Dish &dish3 = dish1;

    cout<<"Address of dish1 is: "<<&dish1<<endl;
    cout<<"Address of dish2 is: "<<&dish2<<endl;
    cout<<"Address of dish3 is: "<<&dish3<<endl;

    dish1.showDish();
    dish2.showDish(); 

    // Dynamic Memory Management   
    // we use operator new
    // new creates the object, when we run the program and memory allocation happens at the time program is running
    Dish* ptr = new Dish("Burger", 120, 4.5);
    cout<<"Dish Pointer ptr is: "<<ptr<<endl;
    ptr->showDish();

    // As a developer i can delete the object when i do not need it
    // Role of Deve to delete the object when no longer requried :)
    delete ptr;

    return 0;
}