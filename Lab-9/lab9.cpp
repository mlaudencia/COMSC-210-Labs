#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
using namespace std;

const int ARRAY_SIZE = 30;

int main(){
    ifstream inFile("fighters.txt");
    array<string, ARRAY_SIZE> fighters;

    for(int i = 0; i < fighters.size(); ++i)
        getline(inFile, fighters[i]);

    inFile.close();

    for(int i = 0; i < fighters.size(); ++i){
        cout << i + 1 << " " << fighters[i] << endl;
    }
}
