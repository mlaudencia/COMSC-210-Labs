#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
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

    vector<string> masterCodes;
    int count = 0;
    int vectorReadTime, listReadTime, setReadTime;
    int vectorSortTime, listSortTime, setSortTime;
    int vectorInsertTime, listInsertTime, setInsertTime;
    int vectorDeleteTime, listDeleteTime, setDeleteTime;
    string code;

    while(fin >> code){
        masterCodes.push_back(code);
    }
    fin.close();

    int masterCodesSize = masterCodes.size();

    // START OF RACE 1
    // START OF VECTOR RACE 1

    auto start = high_resolution_clock::now();

    vector<string> vectorCodes;
    for(int i = 0; i < masterCodesSize; i++){
        vectorCodes.push_back(masterCodes[i]);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    vectorReadTime = duration;

    // END OF VECTOR RACE 1, START OF LIST RACE 1

    start = high_resolution_clock::now();

    list<string> listCodes;
    for(int i = 0; i < masterCodesSize; i++){
        listCodes.push_back(masterCodes[i]);
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    listReadTime = duration;

    // END OF LIST RACE 1, START OF SET RACE 1

     start = high_resolution_clock::now();

    set<string> setCodes;
    for(int i = 0; i < masterCodesSize; i++){
        setCodes.insert(masterCodes[i]);
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    setReadTime = duration;

    // END OF RACE 1, START OF RACE 2
    // START OF VECTOR RACE 2

    start = high_resolution_clock::now();

    sort(vectorCodes.begin(), vectorCodes.end());

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    vectorSortTime = duration;

    // END OF VECTOR RACE 2, START OF LIST RACE 2

    start = high_resolution_clock::now();

    listCodes.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    listSortTime = duration;

    // END OF LIST RACE 2, START OF SET RACE 2

    // Set is already sorted, so can't time it. Per instructions, we just set
    // the time to -1.

    setSortTime = -1;

    // END OF RACE 2, START OF RACE 3
    // START OF VECTOR RACE 3

    
}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
duration.count() references elapsed milliseconds
*/