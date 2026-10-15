#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
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
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}

int main_menu(){
    int input = 0;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "   >  [1] Add a goat" << endl;
        cout << "   >  [2] Delete a goat" << endl;
        cout << "   >  [3] List goats" << endl;
        cout << "   >  [4] Quit" << endl;
        cout << "   >  Choice --> ";

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
    // if(input == 1)
    //     add_goat(trip, names, colors);
}

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

void delete_goat(list<Goat> &t){

}

void display_trip(const list<Goat> &t){
    int count = 0;
    for(Goat g : t){
        cout << "[" << ++count << "] " << g.get_name() << " (" << 
        g.get_age() << ", " << g.get_color() << ")" << endl;
    }
}
