// COMSC-210 | Lab 26 | Jeremy Laudencia

// Here, I included <iostream> and <iomanip> for couts and nicer formatting,
// <chrono> for the timer, <vector>, <list>, and <set> for the races,
// <fstream> and <string> to read in codes.txt, <algorithm> for the built-in
// sort function for vector, and <iterator> to maneuver through list and set.
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

// These two constants are for a neater table of operations.
const int colSize = 12;
const int rowSize = 15;
const int numRuns = 15;
const int numStructs = 3;
const int numTimes = 4;

const int READ = 0;
const int SORT = 1;
const int INSERT = 2;
const int DELETE = 3;

const int VECTOR = 0;
const int LIST = 1;
const int SET = 2;

void displayResults(long long vrt, long long lrt, long long srt, 
                    long long vst, long long lst, long long sst, 
                    long long vit, long long lit, long long sit, 
                    long long vdt, long long ldt, long long sdt);

int main() {
    
    // Here, we read in codes.txt, and return an error if it can't be read in.
    ifstream fin("codes.txt");
    if(!fin){
        cout << "Could not open external file, check if name is correct " <<
        " then restart the program." << endl;
        return 1;
    }

    vector<string> masterCodes;
    long long vectorReadTime, listReadTime, setReadTime;
    long long vectorSortTime, listSortTime, setSortTime;
    long long vectorInsertTime, listInsertTime, setInsertTime;
    long long vectorDeleteTime, listDeleteTime, setDeleteTime;
    string code;

    // This is just so that instead of reading in codes.txt three times for
    // each structure in the race, we just do it once and let each structure
    // read off from the data in the masterCodes vector.
    while(fin >> code){
        masterCodes.push_back(code);
    }
    fin.close();

    int masterCodesSize = masterCodes.size();
    long long allRuns[numRuns][numTimes][numStructs];
    long long averages[numTimes][numStructs] = {0};

    for(int run = 0; run < numRuns; run++){

    // START OF RACE 1
    // START OF VECTOR RACE 1

    auto start = high_resolution_clock::now();

    vector<string> vectorCodes;
    for(int i = 0; i < masterCodesSize; i++){
        vectorCodes.push_back(masterCodes[i]);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][READ][VECTOR] = duration;
    averages[READ][VECTOR] += duration;

    // END OF VECTOR RACE 1, START OF LIST RACE 1

    start = high_resolution_clock::now();

    list<string> listCodes;
    for(int i = 0; i < masterCodesSize; i++){
        listCodes.push_back(masterCodes[i]);
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][READ][LIST] = duration;
    averages[READ][LIST] += duration;

    // END OF LIST RACE 1, START OF SET RACE 1

    start = high_resolution_clock::now();

    set<string> setCodes;
    for(int i = 0; i < masterCodesSize; i++){
        setCodes.insert(masterCodes[i]);
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][READ][SET] = duration;
    averages[READ][SET] += duration;

    // END OF RACE 1, START OF RACE 2
    // START OF VECTOR RACE 2

    start = high_resolution_clock::now();

    sort(vectorCodes.begin(), vectorCodes.end());

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][SORT][VECTOR] = duration;
    averages[SORT][VECTOR] += duration;

    // END OF VECTOR RACE 2, START OF LIST RACE 2

    start = high_resolution_clock::now();

    listCodes.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][SORT][LIST] = duration;
    averages[SORT][LIST] += duration;

    // END OF LIST RACE 2, START OF SET RACE 2

    // Set is already sorted, so can't time it. Per instructions, we just set
    // the time to -1.

    // Since the time is 0, nothing is added to the average sort set time.

    allRuns[run][SORT][SET] = -1;

    // END OF RACE 2, START OF RACE 3
    // START OF VECTOR RACE 3

    start = high_resolution_clock::now();

    vectorCodes.insert(vectorCodes.begin() + (vectorCodes.size()/2), "TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][INSERT][VECTOR] = duration;
    averages[INSERT][VECTOR] += duration;

    // END OF VECTOR RACE 3, START OF LIST RACE 3

    start = high_resolution_clock::now();

    // Here, we use iterators to navigate through the list and insert an
    // element in the middle of it. This was tricky, so I need to learn about
    // iterators and their usage more, and practice using them.
    auto listIt = listCodes.begin();
    advance(listIt, listCodes.size()/2);
    listCodes.insert(listIt, "TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][INSERT][LIST] = duration;
    averages[INSERT][LIST] += duration;

    // END OF LIST RACE 3, START OF SET RACE 3

    start = high_resolution_clock::now();

    // Since set auto sorts its elements, we can't insert in the middle of 
    // the list, so all we can do is insert "TESTCODE" into the set.
    setCodes.insert("TESTCODE");

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][INSERT][SET] = duration;
    averages[INSERT][SET] += duration;

    // END OF RACE 3, START OF RACE 4
    // START OF VECTOR RACE 4

    start = high_resolution_clock::now();

    auto vectorIt = vectorCodes.begin();
    advance(vectorIt, vectorCodes.size()/2);

    vectorCodes.erase(vectorIt);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][DELETE][VECTOR] = duration;
    averages[DELETE][VECTOR] += duration;

    // END OF VECTOR RACE 4, START OF LIST RACE 4

    start = high_resolution_clock::now();
    
    auto listDeleteIt = listCodes.begin();
    advance(listDeleteIt, listCodes.size()/2);

    listCodes.erase(listDeleteIt);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][DELETE][LIST] = duration;
    averages[DELETE][LIST] += duration;

    // END OF LIST RACE 4, START OF SET RACE 4

    start = high_resolution_clock::now();

    auto setDeleteIt = setCodes.begin();
    advance(setDeleteIt, setCodes.size()/2);

    setCodes.erase(setDeleteIt);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start).count();

    allRuns[run][DELETE][SET] = duration;
    averages[DELETE][SET] += duration;

    // END OF RACE 4, ONTO DISPLAYING RESULTS

    cout << "***** RACE RUN # " << run << " *****" << endl;

    displayResults(vectorReadTime, listReadTime, setReadTime,
                   vectorSortTime, listSortTime, setSortTime, 
                   vectorInsertTime, listInsertTime, setInsertTime,
                   vectorDeleteTime, listDeleteTime, setDeleteTime);
    }

}

// displayResults() displays the respective read time, sort time, insert time,
// and delete time of a vector, list, and set data structure.
// arguments: long long vrt, lrt, srt, vst, lst, sst, vit, lit, sit, vdt, ldt, sdt
// returns: nothing

// Originally, I wasn't going to add this, but I think it was better just to 
// have it and not risk getting points off for not having any function 
// prototypes or anything.
void displayResults(long long vrt, long long lrt, long long srt, 
                    long long vst, long long lst, long long sst, 
                    long long vit, long long lit, long long sit, 
                    long long vdt, long long ldt, long long sdt){
    const auto col = setw(colSize);
    const auto row = setw(rowSize);

    cout << left;

    cout << "*** RACE RESULTS ***" << endl;
    cout << "    Operation   |  Vector         List           Set    (all in ns)" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << col << "     Reading    |  " << 
        row << vrt << row << lrt <<
        row << srt  << endl;
    cout << col << "     Sorting    |  " <<
        row << vst << row << lst <<
        row << sst  << endl;
    cout << col << "    Inserting   |  " <<
        row << vit << row << lit <<
        row << sit  << endl;
    cout << col << "    Deleting    |  " <<
        row << vdt << row << ldt <<
        row << sdt  << endl;

}
/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(end - start);
duration.count() references elapsed milliseconds
*/