// COMSC-210 | Lab 23 | Jeremy Laudencia

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
// Here, I added a constant, IGNORE_SIZE, to handle the exceptions when
// the user inputs something out of range or inapplicable to the program.
const int IGNORE_SIZE = 10000;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(const list<Goat> &trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    if()
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;
    // I was having some trouble with the below at first, putting it inside
    // of main_menu() instead of letting it run in main. After thinking about
    // how I probably shouldn't put parameters in main_menu(), I moved it out
    // here to where trip, names, and colors are intialized, which made a lot
    // of sense afterward.
    while(true){
        int user = main_menu();
        if(user == 1)
            add_goat(trip, names, colors);
        else if(user == 2)
            delete_goat(trip);
        else if(user == 3)
            display_trip(trip);
        else if(user == 4)
            break;
    }

    return 0;
}

// main_menu() shows the user options for the goats and returns their choice
// arguments: none
// returns: an int, input
int main_menu(){
    int input = 0;
        cout << endl;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "   >  [1] Add a goat" << endl;
        cout << "   >  [2] Delete a goat" << endl;
        cout << "   >  [3] List goats" << endl;
        cout << "   >  [4] Quit" << endl;
        cout << "   >  Choice --> ";

    // The below basically handles all the cases where the user inputs
    // something thats either out of range of the given choices, or just isn't
    // a number at all. This checks if the user input is a number, that first 
    // if statement returning true if it isn't, then the second just checks if
    // it's in range. I didn't have much difficulty with making main menu other
    // than initally putting the (user == 1) and all in it.
    while(true){
        cin >> input;
        if(cin.fail()){
            cout << "   Invalid input, please choose a number from 1-4" << endl;
            cout << "   >  Choice --> ";
            cin.clear();
            cin.ignore(IGNORE_SIZE, '\n');
        }
        else if(input > 4 || input < 1){
            cout << "   Invalid input, please choose a number from 1-4" << endl;
            cout << "   >  Choice --> ";
            cin.clear();
            cin.ignore(IGNORE_SIZE, '\n');
        }
        else
            break;
    }

    return input;
}

// add_goat() adds a goat of random color, name, and age into the trip.
// arguments: list<Goat> &t, string n[], string c[]
// returns: nothing

// I didn't have much difficulty with add_goat() either. The only thing I
// struggled with here was putting the right stuff into that push_back,
// since I had the order of color and age switched before.
void add_goat(list<Goat> &t, string n[], string c[]){
    int randColor = rand() % SZ_COLORS;
    int randName = rand() % SZ_NAMES;
    int randAge = rand() % MAX_AGE;
    t.push_back(Goat(n[randName], randAge, c[randColor]));
    cout << "Added random goat: " << endl;
    cout << "   Name: " << n[randName] << endl;
    cout << "   Age: " << randAge << endl;
    cout << "   Color: " << c[randColor] << endl;
}

// delete_goat() deletes a goat from the list.
// arguments: list<Goat> &t
// returns: nothing

// I had some trouble here, because I started writing this function before
// having display_trip(), which I needed so that the user could choose what
// goat they wanted to release, so I stopped midway and wrote display_trip(),
// then moved on to this.

// I think a lot of delete_goat() had similar code to main_menu() because of
// the input checks. Something I also had some trouble with was iterating
// through the list. It's definitely a lot more convenient when you're able to
// access elements by index, so this was a bit harder to wrap my head around.
// One thing I don't understand about this is why we use auto it when we can
// just initalize it as an iterator. I think iterators as a whole is something
// I need to study more on.
void delete_goat(list<Goat> &t){
    if(t.empty()){
        cout << "No goats in trip, cannot release any goats." << endl;
        return;
    }
    int indexToDelete = 0;
    display_trip(t);
    cout << "What goat would you like to release?" << endl;
    cout << "Choice --> ";

    while(true){
        cin >> indexToDelete;
        if(cin.fail()){
            cout << "   Invalid input, please choose an index shown" << endl;
            cout << "   >  Choice --> ";
            cin.clear();
            cin.ignore(IGNORE_SIZE, '\n');
        }
        else if(indexToDelete > t.size() || indexToDelete < 1){
            cout << "   Invalid input, please choose an index shown" << endl;
            cout << "   >  Choice --> ";
            cin.clear();
            cin.ignore(IGNORE_SIZE, '\n');
        }
        else
            break;
    }

    auto it = t.begin();
    for(int i = 0; i < indexToDelete - 1; i++){
        ++it;
    }
    t.erase(it);

    cout << "Selected goat has been released." << endl;

}

// display_trip() displays all the goats in a trip.
// arguments: const list<Goat> &t
// returns: nothing

// This was also pretty straightforward to write. The one thing I had in mind
// when writing it was including the first if statement. The code would work
// even if that wasn't there, but I think it's cleaner in display for the user
// to know that the trip is empty.
void display_trip(const list<Goat> &t){
    int count = 0;
    if(t.empty()){
        cout << "Trip is empty, no goats to display." << endl;
    }
    else{
        cout << endl;
        cout << "=== GOAT LIST ===" << endl;
        for(Goat g : t){
            cout << "[" << ++count << "] " << g.get_name() << " (" << 
            g.get_age() << ", " << g.get_color() << ")" << endl;
        }
    }
    cout << endl;
}
