#include <iostream>
#include <string>
using namespace std;

string* reverseArray(string* names);
void displayArray(string* names);

const int SIZE = 5;

int main(){
    string* names = new string[5]{"Doron", "Isaac", "Pot", "Pico", "Jonas"};
    cout << "Original array: ";
    displayArray(names);

    cout << "Reversed array: ";
    displayArray(reverseArray(names));

    delete[] names;
}

string* reverseArray(string* names){
    string* temp = new string[SIZE];
    for(int i = 0; i < SIZE; i++)
        *(temp + i) = *(names + SIZE - 1 - i);
    for(int i = 0; i < SIZE; i++)
        *(names + i) = *(temp + i);
    delete[] temp;
    return names;
}

void displayArray(string* names){
    for(int i = 0; i < SIZE; i++){
        cout << *(names + i) << " ";
    }
    cout << endl;
}