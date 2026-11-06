// COMSC-210 | Lab 32 | Jeremy Laudencia

// Here, I included Car.h and <deque> per the lab instructions,
// <iostream> for outputs to the terminal,
// and <cstdlib> and <ctime> for the random number generation.
#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

// Here, I initialize three constant variables: DQ_INITIAL_SIZE per the lab
// instructions, total chance for the total chance of 55/45, and then the 
// chance for a car to pay the toll and leave the line. I didn't add the
// car join chance, since it would just be the else statement after checking
// if the roll was under CAR_PAY_CHANCE.
const int DQ_INITAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 55;

void displayTollBoothLine(deque<Car>& tBL, int interval, int roll);

int main(){
    srand(time(0));

    int round = 0;
    // Here, I make the tollBoothLine, and then below that, I make the initial
    // queue of the line.
    deque<Car> tollBoothLine;

    for(int i = 0; i < DQ_INITAL_SIZE; i++){
        tollBoothLine.push_back(Car());
    }
    // The below runs until all the cars in the queue pay the toll and leave 
    // the line. As you can see, we have a roll that gets passed into the
    // display function, and that decides whether or not a car is added to
    // the back of the line, or the front car leaves.
    while(!tollBoothLine.empty()){
        int roll = rand() % TOTAL_CHANCE;
        displayTollBoothLine(tollBoothLine, round, roll);
        round++;
    }
}

// displayTollBoothLine() prints out the 
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
            Car leaving = tBL.front();
            cout << "Car Paid: ";
            leaving.print();
            tBL.pop_front();
            cout << "Queue: \n";
        }
        else{
            Car joining = Car();
            cout << "Joined lane: ";
            joining.print();
            tBL.push_back(joining);
            cout << "Queue: \n";
        }
        laneLength = tBL.size();
        if(laneLength == 0){
            cout << "   Empty";
            return;
        }
        for(int i = 0; i < laneLength; i++){
            cout << "   ";
            tBL[i].print();
        }
    }
    
}