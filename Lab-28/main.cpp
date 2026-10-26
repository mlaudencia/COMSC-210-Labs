#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <numeric>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
void accumulate_goats(list<Goat> &trip);
void clear_trip(list<Goat> &trip);
void copy_trip(list<Goat> &trip);
void fill_trip(list<Goat> &trip);
void find_goat(list<Goat> &trip){}
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // create & populate a trip of Goats using std::list of random size 8-15
    int tripSize = rand() % 8 + 8;
    list<Goat> trip;
    int age;
    string name, color;
    for (int i = 0; i < tripSize; i++) {
        age = rand() % MAX_AGE;  // defined in Goat.h
        name = names[rand() % SZ_NAMES];
        color = colors[rand() % SZ_COLORS];
        Goat tmp(name, age, color);
        trip.push_back(tmp);
    }
    
    // Goat Manager 3001 Engine
    int sel = main_menu();
    while (sel != 8) {
        cout << endl;
        switch (sel) {
            case 1:
                cout << "Adding a goat.\n";
                add_goat(trip, names, colors);
                break;
            case 2:    
                cout << "Removing a goat.\n";
                delete_goat(trip);
                break;
            case 3:    
                cout << "Displaying goat data.\n";
                display_trip(trip);
                break;
            case 4:
                cout << "Accumulating goat ages.\n";
                accumulate_goats(trip);
                break;
            case 5:
                cout << "Clearing trip.\n";
                clear_trip(trip);
                break;
            case 6:
                cout << "Copying trip.\n";
                copy_trip(trip);
                break;
            case 7:
                cout << "Filling trip.\n";
                fill_trip(trip);
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
        sel = main_menu();
    }
    

    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Accumulate goat ages\n";
    cout << "[5] Clear trip\n";
    cout << "[6] Copy trip\n";
    cout << "[7] Fill trip (default goat)\n";
    cout << "[8] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 8) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

void delete_goat(list<Goat> &trip) {
    cout << "DELETE A GOAT\n";
    int index = select_goat(trip);
    auto it = trip.begin();
    advance(it, index-1);
    trip.erase(it);
    cout << "Goat deleted. New trip size: " << trip.size() << endl << endl;
}

void add_goat(list<Goat> &trip, string nms[], string cls[]) {
    cout << "ADD A GOAT\n";
    int age = rand() % MAX_AGE;
    string nm = nms[rand() % SZ_NAMES];
    string cl = cls[rand() % SZ_COLORS];
    Goat tmp(nm, age, cl);
    trip.push_back(tmp);
    cout << "Goat added. New trip size: " << trip.size() << endl << endl;
}

void display_trip(list<Goat> trp) {
    int i = 1;
    if(trp.size() == 0){
        cout << "Trip is empty. No goats to list." << endl << endl;
        return;
    }
    for (auto gt: trp)
        cout << "\t" 
             << "[" << i++ << "] "
             << gt.get_name() 
             << " (" << gt.get_age() 
             << ", " << gt.get_color() << ")\n";
}

int select_goat(list<Goat> trp) {
    int input;
    cout << "Make a selection:\n";
    display_trip(trp);
    cout << "Choice --> ";
    cin >> input;
    while (input < 1 || input > trp.size()) {
        cout << "Invalid choice, again --> ";
        cin >> input;
    }
    return input;
}

// accumulate_goats() accumulates the ages of the goats
// arguments: list<Goat> &trp
// returns: nothing
void accumulate_goats(list<Goat> &trp){
    // Here, I use the acccumulate STL algorithm, and then a lambda function.
    // I never really knew what lambda functions were until this week, and
    // I think they seem super conveninent. Anyways, the accumulate function
    // goes through all the goats in trip, adds the ages to inital value 0,
    // then prints it.
    int total = accumulate(trp.begin(), trp.end(), 0, [](int added, const Goat& g){
        return added + g.get_age();
    });
    cout << "Accumulated goat ages: " << total << endl << endl;
}

// clear_trip() clear the trip of all goats.
// arguments: list<Goat> &trp
// returns: nothing
void clear_trip(list<Goat> &trp){
    // This is a pretty straightforward STL algorithm, it just clears all the
    // goats from the trip.
    trp.clear();
    cout << "Trip cleared." << endl << endl;
}

// copy_trip() copies the trip.
// arguments: list<Goat> &trp
// returns: nothing
void copy_trip(list<Goat> &trp){
    // This is also straightforward, the algorithm just copies all the goats
    // of a trip into another trip using that back_inserter() thing. I thought
    // it was super interesting to use, since by copying a trip, you could
    // basically make a save file of a previous trip, like a videogame.
    // For this lab, though, the copy is sort of just made and then gone after
    // the function ends since its a local variable in this function.
    list<Goat> copyTrip;
    copy(trp.begin(), trp.end(), back_inserter(copyTrip));
    cout << "Trip copied. Size of copied trip: " << copyTrip.size() << "\n\n";
}

// fill_trip() fills the trip with default goats.
// arguments: list<Goat> &trp
// returns: nothing
void fill_trip(list<Goat> &trp){
    Goat fillGoat = Goat();
    fill(trp.begin(), trp.end(), fillGoat);
    cout << "Trip filled with default goats.\n\n";
}

// fill_trip() fills the trip with default goats.
// arguments: list<Goat> &trp
// returns: nothing
void find_goat(list<Goat> &trp){
    Goat targetGoat;
    string name;
    cout << "What's the name of the goat to find?: ";
    cin >> name;
    targetGoat.set_name(name);
    auto it = find(trp.begin(), trp.end(), targetGoat);
    if(it != trp.end()){
        
    }
}