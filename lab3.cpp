#include <iostream>
using namespace std;

struct Restaurant{
    string name;
    string address;
    string cuisine;
    double rating;
    int capacity;
};

Restaurant newRestaurant(){
    Restaurant temp;
    cout << "Enter Restaurant name: " << endl;
    cin >> temp.name;
    cout << "Enter Restaurant address: " << endl;
    cin >> temp.address;
    cout << "Enter Restaurant cuisine: " << endl;
    cin >> temp.cuisine;
    cout << "Enter Restaurant rating: " << endl;
    cin >> temp.rating;
    cout << "Enter Restaurant capacity: " << endl;
    cin >> temp.capacity;

    return temp;
}

int main() {
    newRestaurant();
    return 0;
}