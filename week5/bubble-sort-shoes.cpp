#include<iostream>
using namespace std;

class Shoe{

    public:
    string name;
    int price;
    string color;

    Shoe(): name("NA"), price(0), color("black"){

    }

    Shoe(string name, int price, string color): name(name), price(price), color(color){

    }

    void show(){
        cout<<"[Shoe]: "<<name<<" \t "<<price<<" \t "<<color<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

};

void filterPriceLowToHigh(Shoe* shoeArray, int size){

    for(int idx=0; idx<size-1; idx++){

        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(shoeArray[cmpIdx].price > shoeArray[cmpIdx+1].price){
                // swap the values i.e. elements of array :)
                Shoe temp = shoeArray[cmpIdx];
                shoeArray[cmpIdx] = shoeArray[cmpIdx+1];
                shoeArray[cmpIdx+1] = temp;
            }
        }
    }   
}

void filterPriceHighToLow(Shoe* shoeArray, int size){

    for(int idx=0; idx<size-1; idx++){

        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(shoeArray[cmpIdx].price < shoeArray[cmpIdx+1].price){
                // swap the values i.e. elements of array :)
                Shoe temp = shoeArray[cmpIdx];
                shoeArray[cmpIdx] = shoeArray[cmpIdx+1];
                shoeArray[cmpIdx+1] = temp;
            }
        }
    }   
}

void listShoesOnStore(Shoe* shoeArray, int size){
    cout<<"Listing Shoes...\n";
    cout<<"~~~~~~~~~~~~~~~~~~\n";
    for(int idx=0; idx<size; idx++){
        shoeArray[idx].show();
    }
    cout<<endl;
}

int main(){

    Shoe s1("Tennis Shoe", 3599, "White");
    Shoe s2("Stan Smith", 5999, "Black");
    Shoe s3("Supernova", 5159, "Green");
    Shoe s4("ZX 22 Shoe", 4199, "White");
    Shoe s5("Super 2.0", 4799, "Blue");

    // Array of Shoe Objects :)
    Shoe shoes[] = {s1, s2, s3, s4, s5};

    listShoesOnStore(shoes, 5);

    //filterPriceLowToHigh(shoes, 5);
    filterPriceHighToLow(shoes, 5);

    listShoesOnStore(shoes, 5);
    
    return 0;
}
