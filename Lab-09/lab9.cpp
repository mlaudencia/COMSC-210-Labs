// COMSC-210 | Lab 9 | Jeremy Laudencia

// Here, I included a LOT of standard libraries. I included:
// <iostream> for outputs, <fstream> for external file reading,
// <array> and <vector> to use arrays and vectors,
// <numeric> for accumulate(), <string> for the data in my external file,
// and <algorithm> for the sort() and find() functions.
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
using namespace std;

// I make a constant for array size, but this won't be needed for vectors.
const int ARRAY_SIZE = 30;

int main(){
    // We read off the names in my text file, and then add them to
    // the fighters array, fighters being of size ARRAY_SIZE,
    // as seen in the for loop below.
    cout << "ARRAY TESTING" << endl;
    ifstream inFile("fighters.txt");
    array<string, ARRAY_SIZE> arrayFighters;

    for(int i = 0; i < arrayFighters.size(); ++i)
        getline(inFile, arrayFighters[i]);

    // Once we're done with the file, we close it to avoid memory leaks.
    inFile.close();

    // Then, all the names in fighters are printed.
    for(int i = 0; i < arrayFighters.size(); ++i){
        cout << i + 1 << " " << arrayFighters[i] << endl;
    }

    cout << "Testing..." << endl;

    // After that, we test the array member functions that access individual elements.
    cout << "Array Size: " << arrayFighters.size() << endl;
    cout << "Element 15 (fighters.at(15)): " << arrayFighters.at(15) << endl;
    cout << "Element 15 (fighters[15]): " << arrayFighters[15] << endl;
    cout << "Front: " << arrayFighters.front() << endl;
    cout << "Back: " << arrayFighters.back() << endl;
    cout << "Is empty?: " << (arrayFighters.empty() == 0? "Not Empty" : "Empty") << endl;
    cout << "Array address: " << arrayFighters.data() << endl;

    // Here, we use sort() from <algorithm>, and sort the fighters array alphabetically.
    // After they are sorted, the names are printed out again.
    cout << "Alphabetically sorted: ";
    sort(arrayFighters.begin(), arrayFighters.end());
    for(string name : arrayFighters){
        cout << name << endl;
    }
    cout << endl;

    // Here, we reverse sort the fighters array by using rbegin() and rend(), basically
    // starting from the last element to the first and sorting that way.
    cout << "Reverse alphpabetically sorted: ";
    sort(arrayFighters.rbegin(), arrayFighters.rend());
    for(string name : arrayFighters){
        cout << name << endl;
    }
    cout << endl;

    // After that, we use the find() function by having a targetName and going through
    // each element of the array until we find the targetName. 
    string arrayTargetName = "Kai Asakura";
    array<string, ARRAY_SIZE>::iterator arrayFoundName;
    arrayFoundName = find(arrayFighters.begin(), arrayFighters.end(), arrayTargetName);
    cout << "Found Name: " << arrayTargetName;
    if(arrayFoundName != arrayFighters.end()){
        cout << " found in position " << arrayFoundName - arrayFighters.begin() << endl;
        cout << "    Name: " << *arrayFoundName << endl;
    }
    else
        cout << " was not found" << endl;

    // Here, we make two empty arrays and fill them with one value, then
    // use a swap to change the names in one array, the array of Taira's
    // turning into an array of Van's.
    array<string, 4> arrayFourTaira;
    fill(arrayFourTaira.begin(), arrayFourTaira.end(), "Taira");
    array<string, 4> arrayFourVan;
    fill(arrayFourVan.begin(), arrayFourVan.end(), "Van");
    
    cout << "4-element array of Taira: ";
    for(string name : arrayFourTaira) cout << name << " "; cout << endl;
    cout << "4-element array of Van: ";
    for(string name : arrayFourVan) cout << name << " "; cout << endl;

    arrayFourTaira.swap(arrayFourVan);
    cout << "Swapped Taira and Van, Taira array now holds: ";
    for(string name : arrayFourTaira) cout << name << " "; cout << endl;

    // After that, we check out 2D arrays, filling them with the 
    // champion and top 3 fighters at lightweight, making two
    // length-two arrays and then adding those to a single array.
    array<string, 2> row1 = {"Gaethje", "Topuria"};
    array<string, 2> row2 = {"Tsarukyan", "Oliveira"};
    array<array<string, 2>,2> arrayLightWeight = {row1, row2};
    cout << arrayLightWeight[1][1] << endl;

    // Lastly, we try out max_element() and min_element() by going through the
    // fighters array and outputting the alphabetically first and last names.
    // Then, we concatenate all the names using accumulate(). It would look more
    // complete if there weren't spaces in each name.
    cout << "First alphabetically: " << *min_element(arrayFighters.begin(), arrayFighters.end()) << endl;
    cout << "Last alphabetically: " << *max_element(arrayFighters.begin(), arrayFighters.end()) << endl;
    cout << "Concatenated names " << accumulate(arrayFighters.begin(), arrayFighters.end(), string("")) << endl;

    // After that, we do the same for vectors, and it's basically the same thing below.
    // I'm not gonna comment most of the things since they're basically the same.

    cout << "VECTOR TESTING" << endl;
    inFile.open("fighters.txt");
    vector<string> vectorFighters;

    // Instead of using a for loop, we use a while loop that goes until there isn't any name
    // to put as tempName, or until the loop goes through the entire text file.
    string tempName;
    while(getline(inFile, tempName))
        vectorFighters.push_back(tempName);

    inFile.close();

    for(int i = 0; i < vectorFighters.size(); ++i){
        cout << i + 1 << " " << vectorFighters[i] << endl;
    }

    cout << "Testing..." << endl;

    cout << "Vector Size: " << vectorFighters.size() << endl;
    cout << "Element 15 (fighters.at(15)): " << vectorFighters.at(15) << endl;
    cout << "Element 15 (fighters[15]): " << vectorFighters[15] << endl;
    cout << "Front: " << vectorFighters.front() << endl;
    cout << "Back: " << vectorFighters.back() << endl;
    cout << "Is empty?: " << (vectorFighters.empty() == 0? "Not Empty" : "Empty") << endl;
    cout << "Vector address: " << vectorFighters.data() << endl;

    cout << "Alphabetically sorted: ";
    sort(vectorFighters.begin(), vectorFighters.end());
    for(string name : vectorFighters){
        cout << name << endl;
    }
    cout << endl;

    cout << "Reverse alphpabetically sorted: ";
    sort(vectorFighters.rbegin(), vectorFighters.rend());
    for(string name : vectorFighters){
        cout << name << endl;
    }
    cout << endl;

    string vectorTargetName = "Jiri Prochazka";
    vector<string>::iterator vectorFoundName;
    vectorFoundName = find(vectorFighters.begin(), vectorFighters.end(), vectorTargetName);
    cout << "Found Name: " << vectorTargetName;
    if(vectorFoundName != vectorFighters.end()){
        cout << " found in position " << vectorFoundName - vectorFighters.begin() << endl;
        cout << "    Name: " << *vectorFoundName << endl;
    }
    else
        cout << " was not found" << endl;

    // Instead of initializing the vectors with a fill, we are just able to
    // what I think is a built-in fill for the vector library.
    vector<string> vectorFourTaira(4, "Taira");
    vector<string> vectorFourVan(4, "Van");

    
    cout << "4-element vector of Taira: ";
    for(string name : vectorFourTaira) cout << name << " "; cout << endl;
    cout << "4-element vector of Van: ";
    for(string name : vectorFourVan) cout << name << " "; cout << endl;

    vectorFourTaira.swap(vectorFourVan);
    cout << "Swapped Taira and Van, Taira array now holds: ";
    for(string name : vectorFourTaira) cout << name << " "; cout << endl;

    // Here, since vector makes space as you add stuff into it, there's no need
    // to make the vector of size 2 like we did in the array version.
    vector<string> vectorRow1 = {"Gaethje", "Topuria"};
    vector<string> vectorRow2 = {"Tsarukyan", "Oliveira"};
    vector<vector<string>> vectorLightWeight = {vectorRow1, vectorRow2};
    cout << vectorLightWeight[1][1] << endl;

    cout << "First alphabetically: " << *min_element(vectorFighters.begin(), vectorFighters.end()) << endl;
    cout << "Last alphabetically: " << *max_element(vectorFighters.begin(), vectorFighters.end()) << endl;
    cout << "Concatenated names " << accumulate(vectorFighters.begin(), vectorFighters.end(), string("")) << endl;
}
