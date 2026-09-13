// COMSC-210 | Lab 7 | Jeremy Laudencia

// Here, I include <iostream> to use cout and print out my arrays,
// and then <string> so that I can make dynamic arrays of type string.
#include <iostream>
#include <string>
using namespace std;

// Here are prototypes of the two functions needed in the instructions.
// reverseArray() is of type string* so that I can edit the array, names,
// directly from its memory address.
string* reverseArray(string* names);
void displayArray(string* names);

// I make a constant variable SIZE to not have any magic numbers, and so
// that its easier to change size whenever I'd like.
const int SIZE = 5;

int main(){
    // I make a new dynamic array called names of size SIZE, and input my
    // dogs' names to fill it up. After that, it is printed with displayArray().
    // At first, I just made a for loop so that the user could input names, but
    // then reread the instructions and changed it.
    string* names = new string[SIZE]{"Doron", "Isaac", "Pot", "Pico", "Jonas"};
    cout << "Original array: ";
    displayArray(names);

    // After the original array is printed, we reverse it and then print it using
    // one line with reverseArray() inside of displayArray().
    cout << "Reversed array: ";
    displayArray(reverseArray(names));

    // Once both the array and reversed array are printed, the names array is
    // deleted to avoid memory leaks.
    delete[] names;
}

// reverseArray() takes in a dynamic array and reverses the order of its elements.
// arguments: string* names, a dynamic string array
// returns: string* names, but with the order of its elements reversed

// At first, when I made reverseArray(), I put something like *(names + i)
// = *(temp + 1) for some reason, and after running it, my program would sit
// there doing nothing before ending, and I realized it was because it
// was basically emptying the names array and initializing everything to
// nothing. After that, I just switched it around, filled the temp array
// with the reverse order of the elements in the names array, then I made
// the elements in names equal to the ones in temp, then deleted temp for no
// memory leaks.
string* reverseArray(string* names){
    string* temp = new string[SIZE];
    for(int i = 0; i < SIZE; i++)
        *(temp + i) = *(names + SIZE - 1 - i);
    for(int i = 0; i < SIZE; i++)
        *(names + i) = *(temp + i);
    delete[] temp;
    return names;
}

// displayArray() takes in a dynamic array and prints out each element.
// arguments: string* names, a dynamic string array
// returns: nothing
void displayArray(string* names){
    for(int i = 0; i < SIZE; i++){
        cout << *(names + i) << " ";
    }
    cout << endl;
}