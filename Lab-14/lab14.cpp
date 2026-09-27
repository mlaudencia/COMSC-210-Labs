#include <iostream>
#include "Color.h"
#include "Color.cpp"

using namespace std;

int main(){
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