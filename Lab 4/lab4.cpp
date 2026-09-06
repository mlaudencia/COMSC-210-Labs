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

    cout << right << "Color #" << setw(5) <<
            "R" << setw(5) <<
            "G" << setw(5) <<
            "B" << setw(5) << endl;
    cout << "----------------------------" << endl;
    for(int i = 0; i < myColors.size(); ++i){
        cout << right << i+1 << setw(5) <<
            myColors[i].r << setw(5) <<
            myColors[i].g << setw(5) <<
            myColors[i].b << setw(5) << endl;
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