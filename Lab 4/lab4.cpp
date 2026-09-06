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
    srand(time(0));
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