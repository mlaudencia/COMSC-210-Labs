#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int DQ_INITAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 55;

void displaytollBoothLine(const deque<Car>& tBL, int interval, int roll);

int main(){
    srand(time(0));

    int round = 0;
    deque<Car> tollBoothLine;

    for(int i = 0; i < DQ_INITAL_SIZE; i++){
        tollBoothLine.push_back(Car());
    }
    while(!tollBoothLine.empty()){
        int roll = rand() % TOTAL_CHANCE;
        if(roll < CAR_PAY_CHANCE){
            tollBoothLine.pop_front();
        }
        else{
            tollBoothLine.push_back(Car());
        }
        displayTollBoothLine(tollBoothLine, round);
        round++;
    }
}

void displayTollBoothLine(const deque<Car>& tBL, int interval, int roll){
    int lineLength = tBL.size();
    if(interval == 0){
        cout << "Initial Queue:\n";
    }
    else{
        cout << "Time: " << interval << " Operation: ";
        if(roll < CAR_PAY_CHANCE){
            cout << "Car Paid: [" << tBL.front() << "]\n";
        }
    }
    for(int i = 0; i < lineLength; i++){

    }
}