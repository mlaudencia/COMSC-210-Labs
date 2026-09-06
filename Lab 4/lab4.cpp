#include <iostream>
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
vector<Color> myColors;

int main(){
    
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