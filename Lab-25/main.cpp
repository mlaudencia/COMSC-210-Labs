#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;
using namespace std::chrono;

const int colSize = 12;
const int rowSize = 15;

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

    start = high_resolution_clock::now();

    vectorCodes.insert(vectorCodes.begin() + (vectorCodes.size()/2), "TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    vectorInsertTime = duration;

    // END OF VECTOR RACE 3, START OF LIST RACE 3

    start = high_resolution_clock::now();

    auto listIt = listCodes.begin();
    advance(listIt, listCodes.size()/2);
    listCodes.insert(listIt, "TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    listInsertTime = duration;

    // END OF LIST RACE 3, START OF SET RACE 3

    start = high_resolution_clock::now();

    // Since set auto sorts its elements, we can't insert in the middle of 
    // the list, so all we can do is insert "TESTCODE" into the set.
    setCodes.insert("TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    setInsertTime = duration;

    // END OF RACE 3, START OF RACE 4
    // START OF VECTOR RACE 4

    start = high_resolution_clock::now();

    auto vectorIt = vectorCodes.begin();
    advance(vectorIt, vectorCodes.size()/2);

    vectorCodes.erase(vectorIt);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    vectorDeleteTime = duration;

    // END OF VECTOR RACE 4, START OF LIST RACE 4

    start = high_resolution_clock::now();
    
    listCodes.erase(listIt);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    listDeleteTime = duration;

    // END OF LIST RACE 4, START OF SET RACE 4

    start = high_resolution_clock::now();

    auto setIt = setCodes.begin();
    advance(setIt,setCodes.size()/2);

    // For sets, we can't really access any middle point, since it's sorted,
    // and the built-in erase for sets only takes in a value, so we just 
    // delete our inserted value from earlier.
    setCodes.erase("TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    setDeleteTime = duration;

    // END OF RACE 4, ONTO DISPLAYING RESULTS

    const auto col = setw(colSize);
    const auto row = setw(rowSize);

    cout << left;

    cout << "*** RACE RESULTS ***" << endl;
    cout << "            |  Reading        Sorting      " << "  Inserting      Deleting   " << endl;
    cout << col << "   Vector   |  " << 
        row << vectorReadTime << row << vectorSortTime <<
        row << vectorInsertTime << row << vectorDeleteTime << endl;
    cout << col << "    List    |  " <<
        row << listReadTime << row << listSortTime <<
        row << listInsertTime << row << listDeleteTime << endl;
    cout << col << "     Set    |  " <<
        row << setReadTime << row << setSortTime <<
        row << setInsertTime << row << setDeleteTime << endl;

}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
duration.count() references elapsed milliseconds
*/