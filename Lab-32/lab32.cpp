#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int DQ_INITAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 55;

void displayTollBoothLine(deque<Car>& tBL, int interval, int roll);

int main(){
    srand(time(0));

    int round = 0;
    deque<Car> tollBoothLine;

    for(int i = 0; i < DQ_INITAL_SIZE; i++){
        tollBoothLine.push_back(Car());
    }
    displayTollBoothLine(tollBoothLine, 0, 0);
    while(!tollBoothLine.empty()){
        int roll = rand() % TOTAL_CHANCE;
        if(roll < CAR_PAY_CHANCE){
            tollBoothLine.pop_front();
        }
        else{
            tollBoothLine.push_back(Car());
        }
        displayTollBoothLine(tollBoothLine, round, roll);
        round++;
    }
}

void displayTollBoothLine(deque<Car>& tBL, int interval, int roll){
    int laneLength = tBL.size();
    if(interval == 0){
        cout << "Initial Queue:\n";
        for(int i = 0; i < laneLength; i++){
            cout << "   ";
            tBL[i].print();
        }
    }
    else{
        cout << "Time: " << interval << " Operation: ";
        if(roll < CAR_PAY_CHANCE){
            cout << "Car Paid: ";
            tBL.front().print();
            cout << "Queue: \n";
        }
        else{
            cout << "Joined lane: ";
            tBL.back().print();
            cout << "Queue: \n";
        }
        for(int i = 0; i < laneLength; i++){
            cout << "   ";
            tBL[i].print();
        }
    }
    
}