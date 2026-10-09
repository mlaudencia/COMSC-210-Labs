// COMSC-210 | Lab 20 | Jeremy Laudencia

// Here, I just included <ctime> and <cstdlib> for random, the rest
// was already there in the sample code.
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
const int SIZE = 3;

const int MIN = 10000, MAX = 99999;
const int COIN_SIDES = 2;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        // Here, I make a new int flip to make it random if the defualt
        // constructor has 3 legs or 4 like the instructions asked for.
        int flip = rand() % COIN_SIDES;
        if(flip == 0){
            legs = 3;
        } else{
            legs = 4;
        }
        // Here, we make the random prices like the instructions asked,
        // keeping price inside of the for loop so a new price is generated
        // with every iteration.
        for (int i = 0; i < SIZE; i++){
            double price = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
            prices[i] = price;
        }
    }

    // Here, I made the constructor take in two parameters, one for legs and
    // one for size, taking in a double array of SIZE, and then making the 
    // prices array equal to the inputted array.
    Chair(int l, double arr[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = arr[i];
    }

    // setters and getters
    // The below was already in the sample code, so I left it as is.
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    // Here, I made a destructor for Chair since I saw that prices wasn't
    // getting deleted at the end of the program, which'll lead to memory
    // leaks.
    ~Chair(){
        delete[] prices;
    }
};

int main() {
    cout << fixed << setprecision(2);

    // I don't think I was supposed to touch these first two new chair
    // objects of chairPtr and livingChair, but I just changed the livingChair
    // so that it would not be an error anymore, making it fit with the new two
    // parameter constructor. I also deleted chairPtr because the sample didn't.

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    //creating dynamic chair object with constructor
    double livingChairPrices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, livingChairPrices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    // Since I assumed that the instructions asked for collection just to
    // be made with the default constructor, I commented the below code out
    // and just printed collection, since the default constructor already
    // set the legs and prices for however many chairs there were.

    // collection[0].setLegs(4);
    // collection[0].setPrices(441.41, 552.52, 663.63);
    // collection[1].setLegs(4);
    // collection[1].setPrices(484.84, 959.59, 868.68);
    // collection[2].setLegs(4);
    // collection[2].setPrices(626.26, 515.15, 757.57);

    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    // At the end here, I also added a delele collection just to be safe with
    // memory and all.
    delete[] collection;
    collection = nullptr;

    return 0;
}