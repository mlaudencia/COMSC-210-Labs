#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <numeric>
#include <algorithm>
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
void find_goat(list<Goat> &trip);
void reverse_trip(list<Goat> &trip);
void sort_trip_age(list<Goat> &trip);
void sort_trip_name(list<Goat> &trip);
void unique_trip_name(list<Goat> &trip);
void unique_trip_age(list<Goat> &trip);
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
    while (sel != 14) {
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
            case 8:
                cout << "Finding goat.\n";
                find_goat(trip);
                break;
            case 9:
                cout << "Reversing trip.\n";
                reverse_trip(trip);
                break;
            case 10:
                cout << "Sorting trip by name.\n";
                sort_trip_name(trip);
                break;
            case 11:
                cout << "Sorting trip by age.\n";
                sort_trip_age(trip);
                break;
            case 12:
                cout << "Keeping unique by name.\n";
                unique_trip_name(trip);
                break;
            case 13:
                cout << "Keeping unique by age.\n";
                unique_trip_age(trip);
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
        sel = main_menu();
    }
    

    return 0;
}

// main_menu() lets the user choose an option from a menu and returns it.
// arguments: nothing
// returns: choice, the user's chosen option
int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Accumulate goat ages\n";
    cout << "[5] Clear trip\n";
    cout << "[6] Copy trip\n";
    cout << "[7] Fill trip (default goat)\n";
    cout << "[8] Find goat\n";
    cout << "[9] Reverse trip\n";
    cout << "[10] Sort trip (name)\n";
    cout << "[11] Sort trip (age)\n";
    cout << "[12] Make trip unique (name)\n";
    cout << "[13] Make trip unique (age)\n";
    cout << "[14] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 14) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

// delete_goat() deletes a goat from the trip.
// arguments: list<Goat> &trip
// returns: nothing
void delete_goat(list<Goat> &trip) {
    cout << "DELETE A GOAT\n";
    int index = select_goat(trip);
    auto it = trip.begin();
    advance(it, index-1);
    trip.erase(it);
    cout << "Goat deleted. New trip size: " << trip.size() << endl << endl;
}

// add_goat() adds a goat to the trip.
// arguments: list<Goat> &trip, string nms[], string cls[]
// returns: nothing
void add_goat(list<Goat> &trip, string nms[], string cls[]) {
    cout << "ADD A GOAT\n";
    int age = rand() % MAX_AGE;
    string nm = nms[rand() % SZ_NAMES];
    string cl = cls[rand() % SZ_COLORS];
    Goat tmp(nm, age, cl);
    trip.push_back(tmp);
    cout << "Goat added. New trip size: " << trip.size() << endl << endl;
}

// display_trip() displays the goats of a trip.
// arguments: list<Goat> trp
// returns: nothing
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

// select_goat() lets the user choose the index of a goat from the trip.
// arguments: list<Goat> trp
// returns: input, the user's chosen index
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
    // I thought building this function was really interesting. I didn't know
    // about distance() that I could use for lists, but I searched it up and
    // learned about it since I thought the print would be cleaner if it had
    // the index of the goat.

    // I also learned about find_if(). I initially tried to use find() here,
    // but I basically made a blank goat with just its name, and compared all
    // the goats and the targetGoat to see if they were the same, but that
    // meant the program was comparing an incomplete goat to a complete one.
    // Since that didn't work out, I opted to use find_if(), which basically
    // just makes sure we can just compare the names of the goats.
    string name;
    cout << "What's the name of the goat to find?: ";
    cin >> name;
    auto it = find_if(trp.begin(), trp.end(), [name](const Goat& g){
        return g.get_name() == name;
    });

    if(it != trp.end()){
        int index = distance(trp.begin(), it);
        // I also added index+1, since it would return an index of index-1.
        cout << name << " found at index " << index+1 << "\n\n";
    } else{
        cout << name << " was sadly not found." << "\n\n";
    }
}

// reverse_trip() reverse the order of the goats in a trip.
// arguments: list<Goat> &trp
// returns: nothing
void reverse_trip(list<Goat> &trp){
    // This honestly feels like cheating with how short it is. In past labs,
    // I'd have to make a whole for i loop starting from the last element going
    // all the way back and yada yada yada, and it would be pretty long, but now
    // you can just do it with one line of code. Lists and STL algorithms 
    // are crazy.
    reverse(trp.begin(), trp.end());
    cout << "Trip has been reversed.\n\n";
}

// I know that these two sort functions just fall under one milestone, but
// I just thought it'd be cool to do both. Plus, just seeing how short these
// functions are after going through manually making sort functions in the
// previous labs is just crazy to see.

// One thing I noticed about these two functions after a huge error was that
// the way they call that STL algorithm is different. They don't use
// trp.begin() or trp.end() like the others, just gets called under it. I
// see the same for std::unique in the STL algorithms lessons, and I am 
// wondering why that is.

// sort_trip_age() sorts the trip by youngest to oldest.
// arguments: list<Goat> &trp
// returns: nothing
void sort_trip_age(list<Goat> &trp){
    trp.sort([](const Goat& a, const Goat& b){
        return a.get_age() < b.get_age();
    });
    cout << "Trip has been sorted by age.\n\n";
}

// sort_trip_name() sorts the trip by names in alphabetical order.
// arguments: list<Goat> &trp
// returns: nothing
void sort_trip_name(list<Goat> &trp){
    trp.sort([](const Goat& a, const Goat& b){
        return a.get_name() < b.get_name();
    });
    cout << "Trip has been sorted by name.\n\n";
}

// A good thing I noticed while testing my unique functions were that they had
// to be sorted according to their respective trait, so the trip needs to be
// sorted by name to use unique_trip_name(), and same for age.

// Something else I found interesting about unique was that it only worked for
// adjacent/consecutive elements in a range, and I had some difficulty grasping
// that concept, but learned about differentiating a element's write position
// versus its position in the list, which helped a lot.

// unique_trip_name() keeps unique-named goats and removes duplicates.
// arguments: list<Goat> &trp
// returns: nothing
void unique_trip_name(list<Goat> &trp){
    trp.unique([](const Goat& a, const Goat& b){
        return a.get_name() == b.get_name();
    });
    cout << "All unique-named goats in trip have been kept.\n\n";
}

// unique_trip_age() keeps unique-aged goats and removes duplicates.
// arguments: list<Goat> &trp
// returns: nothing
void unique_trip_age(list<Goat> &trp){
    trp.unique([](const Goat& a, const Goat& b){
        return a.get_age() == b.get_age();
    });
    cout << "All unique-aged goats in trip have been kept.\n\n";
}

