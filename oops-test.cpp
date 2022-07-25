#include<iostream>
using namespace std;

class Dish{ 

    public:
    
    // Attributes or Data members or instance variables
    // non static: property of object
    string name;
    int price;
    int quantity;
    float ratings;

    // static belongs to class
    // property of class
    static int totalDishes;       // default value is 0
    static int totalDishQuantity; // default value is 0

    Dish(): name("Noodles"), price(100), quantity(1), ratings(3.5){
        totalDishes++;
        totalDishQuantity += quantity;
    }

    // Constructor: Parameterized Constructor
    Dish(string name, int price, int quantity, float ratings): name(name), price(price), quantity(quantity), ratings(ratings){
        totalDishes++;
        totalDishQuantity += quantity;
    }

    void increment(){
        ++quantity;
        ++totalDishQuantity;
    }

    void decrement(){
        --quantity;
        --totalDishQuantity;
    }

    // Function
    void showDish(){
        cout<<"Dish is: "<<name<<" \u20b9"<<price<<" "<<quantity<<" "<<ratings<<endl;
    }
    
    // Property of Class
    static void show(){
        cout<<"Total Dishes: "<<totalDishes<<endl;
        cout<<"Total Dishes Quantity: "<<totalDishQuantity<<endl;
    }

};

// declare for compiler totalDishes is a static member of class Dish
int Dish::totalDishes;
int Dish::totalDishQuantity;

int main(){

    Dish dish1;                         // N: Noodles   | Q: 1
    Dish dish2("Pizza", 300, 2, 4.5);   // N: Pizza     | Q: 2
    Dish &dish3 = dish2; // reference to dish2

    // Q: How many Objects we created ? A: 2

    dish1.increment(); // 2
    dish2.increment(); // 3
    dish3.increment(); // 4

    dish2.decrement(); // 3
    dish3.decrement(); // 2

    dish2.increment(); // 3


    dish1.showDish();   // 56: N: Noodles   | Q: 2
    dish2.showDish();   // 57: N: Pizza     | Q: 3
    dish3.showDish();   // 58: N: Pizza     | Q: 3
 

    // static functions to be executed by class name
    Dish::show();

    return 0;
}
