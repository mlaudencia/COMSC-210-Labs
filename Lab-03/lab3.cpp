// COMSC-210 | Lab 3 | Jeremy Laudencia

#include <iostream>
#include <string>
using namespace std;

struct Restaurant {  // creates a new Restaurant
    string name;
    string address;
    string cuisine;
    double rating;
    int capacity;
};

// newRestaurant() creates a new restaurant with user inputs. 
// arguments: none
// returns: A restaurant object that contains the user's inputted data.
Restaurant newRestaurant();

// printRestaurant() takes a restaurant passed in and prints its data one by one
// arguments: a Restaurant, r
// returns: nothing
void printRestaurant(Restaurant r);


int main() {

    Restaurant r1 = newRestaurant(); // milestone 2 says create four restaurant objects, then
    Restaurant r2 = newRestaurant(); // manipulate them? I assumed it meant print, so I made 
    Restaurant r3 = newRestaurant(); // four restaurants and printed them all at the same time.
    Restaurant r4 = newRestaurant();
    printRestaurant(r1);             // Each one of these prints out the data for the restaurant inputted. 
    printRestaurant(r2);
    printRestaurant(r3);
    printRestaurant(r4);
}

Restaurant newRestaurant(){  
    Restaurant temp;
    cout << "Enter Restaurant name: " << endl;
    getline(cin, temp.name); // used getline() here, since when I used cin for all user
                             // inputs, it skipped inputs, and getline() doesn't
    cout << "Enter Restaurant address: " << endl;
    getline(cin, temp.address);
    cout << "Enter Restaurant cuisine: " << endl;
    getline(cin, temp.cuisine);
    cout << "Enter Restaurant rating: " << endl;
    cin >> temp.rating;      // I didn't use getline() here, because that 
                             // skipping input error was happening again.
    cout << "Enter Restaurant capacity: " << endl;
    cin >> temp.capacity; 
    cin.ignore(); // I was  confused why some inputs were being skipped in my old code. 
                  // Searching it up, I learned cin >> leaves its newline when you press
                  // Enter and only reads the user input, so when the next restaurant 
                  // comes around, the newline left over only gets seen then and skips 
                  // that getline, so nothing can be inputted for the nextrestaurant's name.
    return temp;
}

void printRestaurant(Restaurant r){
    cout << "Restaurant name: " << r.name << endl; 
    cout << "   Address: " << r.address << endl;
    cout << "   Cuisine: " << r.cuisine << endl;
    cout << "   Rating: " << r.rating << endl;
    cout << "   Capacity: " << r.capacity << endl;
}