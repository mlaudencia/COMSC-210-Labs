#include <iostream>
#include <fstream>
#include <array>
#include <numeric>
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

    array<string, 4> fourTaira;
    fill(fourTaira.begin(), fourTaira.end(), "Taira");
    array<string, 4> fourVan;
    fill(fourVan.begin(), fourVan.end(), "Van");
    
    cout << "4-element array of Taira: ";
    for(string name : fourTaira) cout << name << " "; cout << endl;
    cout << "4-element array of Van: ";
    for(string name : fourVan) cout << name << " "; cout << endl;

    fourTaira.swap(fourVan);
    cout << "Swapped Taira and Van, Taira array now holds: ";
    for(string name : fourTaira) cout << name << " "; cout << endl;

    array<string, 2> row1 = {"Gaethje", "Topuria"};
    array<string, 2> row2 = {"Tsarukyan", "Oliveira"};
    array<array<string, 2>,2> lightWeight = {row1, row2};
    cout << lightWeight[1][1] << endl;

    cout << "First alphabetically: " << *min_element(fighters.begin(), fighters.end()) << endl;
    cout << "Last alphabetically: " << *max_element(fighters.begin(), fighters.end()) << endl;
    cout << "Concatenated names " << accumulate(fighters.begin(), fighters.end(), string("")) << endl;
}
