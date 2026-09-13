#include <iostream>
using namespace std;

void enterArrayData(double* numbers);
void outputArrayData(double* numbers);
void sumArray(double* numbers);

const int SIZE = 5;

double* numbers = new double[SIZE];

int main(){
    enterArrayData(numbers);
    outputArrayData(numbers);
    sumArray(numbers);
}

void enterArrayData(double* numbers){
    cout << "Data entry for the array:" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << "   > Element #" << i << ": ";
        cin >> numbers[i];
    }
    cout << "Data entry complete." << endl;
}

void outputArrayData(double* numbers){
    cout << "Outputting array elements: ";
    for(int i = 0; i < SIZE; i++)
        cout << numbers[i] << " ";
    cout << endl;
}

void sumArray(double* numbers){
    double total;
    for(int i = 0; i < SIZE; i++)
        total += numbers[i];
    cout << "Sum of values: " << total;
}