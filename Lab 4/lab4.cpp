// COMSC-210 | Lab 4 | Jeremy Laudencia

// included <random> to generate random numbers,
// <vector> to store each Color generated,
// and <iomanip> to have a nice format when printed.
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
using namespace std;


// struct for a new Color, as given by the
// info before Milestone 1, taking in a
// red, green, and blue value
struct Color{
    int r;
    int g;
    int b;
};

// makeNewColor() makes a new color with user inputs
// arguments: none
// returns: A Color object containing the three user inputs for r, g, and b
Color makeNewColor(); 

// newColor() makes a new color by taking in given r, g, and b values
// arguments: int r, g, b
// returns: A color object containing the three parameter inputs for r, g, and b 
Color newColor(int r, int g, int b);

// Originally, I had makeNewColor() as newColor(), but after
// reading Milestone 2, I  changed it so that there would be a
// function for user input colors, and then general parameter colors.

// printColor() takes in a Color c and prints its r, g, and b values
// arguments: Color c
//returns: nothing
void printColor(Color c);

int main(){
    // initialized an empty vector of type Color for later
    vector<Color> myColors;
    // put this to generate actual random numbers instead of repeated ones
    srand(time(0));
    // randomNum() generates a random number between 25-50 for how many
    // colors that are going to be printed
    int randomNum = rand() % (50-25+1) + 25;
    for(int i = 0; i < randomNum; i++){
        int randomR = rand() % (255+1);
        int randomG = rand() % (255+1);
        int randomB = rand() % (255+1);
        myColors.push_back(newColor(randomR, randomG, randomB));
    }

    cout << right << setw(10) 
         << "Color #  " << setw(10) <<
            "R value" << setw(10) <<
            "G value" << setw(10) <<
            "B value" << setw(10) << endl;
    cout << "-------------------------------------------" << endl;
    for(int i = 0; i < myColors.size(); ++i){
        cout << right << setw(5) 
             << i+1 << setw(11) <<
            myColors[i].r << setw(11) <<
            myColors[i].g << setw(11) <<
            myColors[i].b << endl;
    }

}

Color makeNewColor(){
    Color temp;
    cout << "Enter color's r value: " << endl;
    cin >> temp.r;
    cout << "Enter color's g value: " << endl;
    cin >> temp.g;
    cout << "Enter color's r value: " << endl;
    cin >> temp.b;

    return temp;
}

Color newColor(int r, int g, int b){
    Color temp;
    temp.r = r;
    temp.g = g;
    temp.b = b;
    return temp;
}

void printColor(Color c){
    cout << "Color values:" << endl;
    cout << "   R: " << c.r << endl;
    cout << "   G: " << c.g << endl;
    cout << "   B: " << c.b << endl;
}