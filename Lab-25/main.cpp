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

    string masterCodes[CODES_SIZE];
    int count = 0;
    int vectorTime, listTime, setTime;
    string code;

    while(fin >> code && count < CODES_SIZE){
        masterCodes[count] = code;
        count++;
    }

    auto start = high_resolution_clock::now();

    vector<string> vectorCodes;
    for(int i = 0; i < CODES_SIZE; i++){
        vectorCodes.push_back(masterCodes[i]);
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start).count();

    vectorTime = duration;

    start = high_resolution_clock::now();

    list<string> listCodes;
    for(int i = 0; i < CODES_SIZE; i++){
        listCodes.push_back(masterCodes[i]);
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    listTime = duration;

     start = high_resolution_clock::now();

    set<string> setCodes;
    for(int i = 0; i < CODES_SIZE; i++){
        setCodes.insert(masterCodes[i]);
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    cout << "*** FIRST RACE: READING ***" << endl;
    cout << "RESULTS: " << endl;
    cout << "   Vector Time: " << vectorTime << endl;
    cout << "   List Time: " << listTime << endl;
    cout << "   Set Time: " << setTime << endl;
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/