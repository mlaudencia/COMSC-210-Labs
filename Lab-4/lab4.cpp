// COMSC-210 | Lab 4 | Jeremy Laudencia

// included <cstdlib> and <ctime> to generate random numbers,
// <vector> to store each Color generated,
// and <iomanip> to have a nice format when printed.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int MIN_COLORS = 25;
const int MAX_COLORS = 50;
const int MAX_RGB = 255;
const int COL_WIDTH = 15;

// struct for a new Color, as given by the
// info before Milestone 1, taking in a
// red, green, and blue value
struct Color{
    int r;
    int g;
    int b;
};

// newColor() makes a new color by taking in given r, g, and b values
// arguments: int r, g, b
// returns: A color object containing the three parameter inputs for r, g, and b 
Color newColor(int r, int g, int b);


int main(){
    // initialized an empty vector of type Color for later
    vector<Color> myColors;
    // put this to generate actual random numbers instead of repeated ones
    srand(time(0));
    // randomNum() generates a random number between 25-50 for how many
    // colors that are going to be printed
    int randomNum = rand() % (MAX_COLORS-MIN_COLORS+1) + MIN_COLORS;
    for(int i = 0; i < randomNum; i++){
        // The below generates random numbers from 0-255 for
        // a color's r, g, and b hues
        int randomR = rand() % (MAX_RGB+1);
        int randomG = rand() % (MAX_RGB+1);
        int randomB = rand() % (MAX_RGB+1);
        // After we generate those, we make a new Color with the
        // random RGB, and then put it into our vector, myColors.
        myColors.push_back(newColor(randomR, randomG, randomB));
    }

    // The below is just a bunch of formatting for the print
    // so that it looks nice.
    cout << left << setw(COL_WIDTH) 
         << "Color #" << setw(COL_WIDTH) <<
            "R value" << setw(COL_WIDTH) <<
            "G value" << setw(COL_WIDTH) <<
            "B value" << endl;
    cout << "-----------------------------------------------------" << endl;
    // Prints out each color in myColors and its r, g, and b values
    for(int i = 0; i < myColors.size(); ++i){
        cout << left << setw(COL_WIDTH) 
             << i+1 << setw(COL_WIDTH) <<
            myColors[i].r << setw(COL_WIDTH) <<
            myColors[i].g << setw(COL_WIDTH) <<
            myColors[i].b << endl;
    }

}

    // This takes in three parameters for r, g, and b,
    // then returns a Color from those given ints. 
Color newColor(int r, int g, int b){
    Color temp;
    temp.r = r;
    temp.g = g;
    temp.b = b;
    return temp;
}
