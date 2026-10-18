#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

const int CODES_SIZE = 20000;

int main() {
    
    ifstream fin("codes.txt");
    if(!fin){
        cout << "Could not open external file, check if name is correct " <<
        " then restart the program." << endl;
        return 1;
    }

    int masterCodes[CODES_SIZE];
    int count = 0;
    int number;

    while(fin >> number && count < CODES_SIZE){
        masterCodes[count] = number;
        count++;
    }
    
    vector<int> vectorCodes;



    auto start = high_resolution_clock::now();



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/