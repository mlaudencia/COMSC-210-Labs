// COMSC-210 | Lab 16 | Jeremy Laudencia

// Comments start at Color.h

// Now, we include <iostream> to handle hardcoded color name
// printing, then the Color.h file. I thought I needed both
// the cpp file and h file, but apparently not after searching
// it up, so as I am writing this, I just removed it.
#include <iostream>
#include "Color.h"

// I actually use the standard namespace here, so I don't have
// to write std:: a bunch of times for the couts and endls below.
using namespace std;

int main(){
    // Here, I make 6 different colors using different constructors.
    // This is because I wanted to try making the code look neater. I
    // personally think it does when you look at both below. Anyways,
    // the only difference is that one doesn't include the name of the 
    // color while the other does, color1 not including, and color2
    // including.
    Color defaultColor;

    Color red1 = Color(255, 0, 0);
    Color green1 = Color(0, 255, 0);
    Color blue1 = Color(0, 0, 255);
    Color pink1 = Color(255, 197, 211);
    Color white1 = Color(255, 255, 255);
    Color black1 = Color(0, 0, 0);

    Color red2 = Color("red", 255, 0, 0);
    Color green2 = Color("green", 0, 255, 0);
    Color blue2 = Color("blue", 0, 0, 255);
    Color pink2 = Color("pink", 255, 197, 211);
    Color white2 = Color("white", 255, 255, 255);
    Color black2 = Color("black", 0, 0, 0);

    
    // As you can see, comparing the two methods, the number of lines
    // used is cut in half, and that's definitely more organized than 
    // printing each color's name before printing their data.
    cout << "--- Default Color---" << endl;
    defaultColor.print1();

    cout << "--- Red Color ---" << endl;
    red1.print1();
    cout << "--- Green Color ---" << endl;
    green1.print1();
    cout << "--- Blue Color ---" << endl;
    blue1.print1();

    cout << "--- Pink Color ---" << endl;
    pink1.print1();
    cout << "--- White Color ---" << endl;
    white1.print1();
    cout << "--- Black Color ---" << endl;
    black1.print1();

    // Other method 

    red2.print2();
    green2.print2();
    blue2.print2();

    pink2.print2();
    white2.print2();
    black2.print2();


}