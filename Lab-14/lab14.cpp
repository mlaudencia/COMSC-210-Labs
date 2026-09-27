#include <iostream>
#include "Color.h"
#include "Color.cpp"

using namespace std;

int main(){
    Color red = Color(255, 0, 0);
    Color green = Color(0, 255, 0);
    Color blue = Color(0, 0, 255);
    Color pink = Color(255, 197, 211);
    Color white = Color(255, 255, 255);
    Color black = Color(0, 0, 0);

    
    cout << "--- Red Color ---" << endl;
    red.print();
    cout << "--- Green Color ---" << endl;
    green.print();
    cout << "--- Blue Color ---" << endl;
    blue.print();

    cout << "--- Pink Color ---" << endl;
    pink.print();
    cout << "--- White Color ---" << endl;
    white.print();
    cout << "--- Black Color ---" << endl;
    black.print();
}