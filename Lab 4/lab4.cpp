#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
using namespace std;

struct Color{
    int r;
    int g;
    int b;
};

Color newColor();
void printColor(Color c);

int main(){
    vector<Color> myColors;
    Color c1 = newColor();
    printColor(c1);
    myColors.push_back(c1);

    cout << right << setw(10) 
         << "Color #  " << setw(10) <<
            "R value" << setw(10) <<
            "G value" << setw(10) <<
            "B value" << setw(10) << endl;
    cout << "----------------------------------------------" << endl;
    for(int i = 0; i < myColors.size(); ++i){
        cout << right << setw(5) 
             << i+1 << setw(11) <<
            myColors[i].r << setw(11) <<
            myColors[i].g << setw(11) <<
            myColors[i].b << endl;
    }

}

Color newColor(){
    Color temp;
    cout << "Enter color's r value: " << endl;
    cin >> temp.r;
    cout << "Enter color's g value: " << endl;
    cin >> temp.g;
    cout << "Enter color's r value: " << endl;
    cin >> temp.b;

    return temp;
}

void printColor(Color c){
    cout << "Color values:" << endl;
    cout << "   R: " << c.r << endl;
    cout << "   G: " << c.g << endl;
    cout << "   B: " << c.b << endl;
}