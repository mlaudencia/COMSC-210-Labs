// COMSC-210 | Lab 6 | Jeremy Laudencia

#include <iostream>
using namespace std;

// Added prototypes for each function needed
void enterArrayData(double* numbers);
void outputArrayData(double* numbers);
double sumArray(double* numbers);

// Made a constant variable for size so that there aren't any magic numbers
// I feel like I'm always tempted to have magic numbers, but it's a good
// thing to practice not having those hardcoded numbers just sitting around,
// and knowing what numbers are used for. It also makes it easier to change
// throughout a program with just one change instead of many all around.
const int SIZE = 5;

int main(){
    // I dynamically allocate an array of doubles, numbers, and then store its
    // address in a pointer. I definitely need more practice with it, since like
    // the above comment, I sort of just default to not using pointers.
    double* numbers = new double[SIZE];

    // This allows the user to input SIZE many elements into the array numbers.
    enterArrayData(numbers);
    // This prints out the inputted elements all on one line.
    outputArrayData(numbers);
    // This prints out the sum of array, just adding all the elements of numbers together.
    cout << "Sum of values: "<< sumArray(numbers);

    // After using numbers, I delete it so that there isn't a memory leak. I forgot to 
    // do this at first, so I definitely need to keep it in mind more.
    delete[] numbers;
}

// enterArrayData() takes in the dynamic array, numbers, and allows
// the user to input however many values numbers is initialized by.
// arguments: double* numbers, a dynamic array
// returns: nothing
void enterArrayData(double* numbers){
    cout << "Data entry for the array:" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << "   > Element #" << i << ": ";
        cin >> *(numbers + i);
    }
    cout << "Data entry complete." << endl;
}

// outputArrayData() takes in the dynamic array, numbers, and prints
// them all on one line.
// arguments: double* numbers
// returns: nothing
void outputArrayData(double* numbers){
    cout << "Outputting array elements: ";
    for(int i = 0; i < SIZE; i++)
        cout << *(numbers + i) << " ";
    cout << endl;
}

// sumArray() takes in the dynamic array, numbers, and adds
// all of the array elements together, and returns the total.
// arguments: double* numbers
// returns: the total value of elements in the array, total
double sumArray(double* numbers){
    double total = 0;
    for(int i = 0; i < SIZE; i++)
        total += *(numbers + i);
    return total;
}