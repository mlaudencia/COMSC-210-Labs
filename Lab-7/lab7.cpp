#include <iostream>
#include <string>
using namespace std;

string* reverseArray(string* names);
void displayArray(string* names);

const int SIZE = 5;

int main(){
    string* names = new string[SIZE];
    cout << "Original array: ";
    for(int i = 0; i < SIZE; i++){
        cin >> names[i];
    }
    displayArray(names);

    // reverseArray(names);
    // cout << "Reversed array: ";
    // displayArray(names);
}

string* reverseArray(string* names){
    string* temp = new string[SIZE];
    for(int i = 0; i < SIZE; i++){
        *(names + SIZE - i) = *(temp + i);
    }
    return temp;
}