#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
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

    cout << "Testing..." << endl;

    cout << "Array Size: " << fighters.size() << endl;
    cout << "Element 15 (fighters.at(15)): " << fighters.at(15) << endl;
    cout << "Element 15 (fighters[15]): " << fighters[15] << endl;
    cout << "Front: " << fighters.front() << endl;
    cout << "Back: " << fighters.back() << endl;
    cout << "Is empty?: " << (fighters.empty() == 0? "Not Empty" : "Empty") << endl;
    cout << "Array address: " << fighters.data() << endl;
    cout << "Alphabetically sorted: ";
    sort(fighters.begin(), fighters.end());
    for(string name : fighters){
        cout << name << endl;
    }
    cout << endl;
    cout << "Reverse alphpabetically sorted: ";
    sort(fighters.rbegin(), fighters.rend());
    for(string name : fighters){
        cout << name << endl;
    }
    cout << endl;
    string targetName = "Kai Asakura";
    array<string, ARRAY_SIZE>::iterator foundName;
    foundName = find(fighters.begin(), fighters.end(), targetName);
    cout << "Found Name: " << targetName;
    if(foundName != fighters.end())
        cout << " found in position " << foundName - fighters.begin() << endl;
    else
        cout << " was not found" << endl;
    cout << "    Name: " << *foundName << endl;
}
