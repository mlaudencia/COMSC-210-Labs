// COMSC-210 | Lab 3 | Jeremy Laudencia

#include <iostream>
#include <string>
using namespace std;

struct Restaurant{  // creates a new Restaurant
    string name;
    string address;
    string cuisine;
    double rating;
    int capacity;
};

Restaurant newRestaurant(){  // newRestaurant() takes in user inputs for the name, address, type of cuisine, rating, and capacity of a
    Restaurant temp;         // restaurant, and returns the new restaurant.
    cout << "Enter Restaurant name: " << endl;
    getline(cin, temp.name); // used getline() here, since when I used cin for all user inputs, it skipped inputs, and getline() doesn't
    cout << "Enter Restaurant address: " << endl;
    getline(cin, temp.address);
    cout << "Enter Restaurant cuisine: " << endl;
    getline(cin, temp.cuisine);
    cout << "Enter Restaurant rating: " << endl;
    cin >> temp.rating;      // I didn't use getline() here, because that skipping input error was happening just in the opposite way.
    cout << "Enter Restaurant capacity: " << endl; // It would skip because of numbers, while the previous one skipped because of
    cin >> temp.capacity;                          // spaces in the input.

    return temp;
}

int main() {
    newRestaurant(); 
}