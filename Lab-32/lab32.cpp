// COMSC-210 | Lab 32 | Jeremy Laudencia

// Here, I included Car.h and <deque> per the lab instructions,
// <iostream> for outputs to the terminal,
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
const int DQ_INITIAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 46;
const int CAR_JOIN_CHANCE = 39;
const int EMPTY_LANE_JOIN_CHANCE = 50;

const int NUM_LANES = 4;
const int NUM_TIME_INTERVALS = 20;


void displayTollBoothLine(deque<Car>& tBL, int interval, int roll);

int main(){
    srand(time(0));

    deque<Car> lanes[NUM_LANES];

    int round = 0;
    // Here, I make the tollBoothLine, and then below that, I make the initial
    // queue of the line.
    for(int i = 0; i < NUM_LANES; i++){
        for(int j = 0; j < DQ_INITIAL_SIZE; j++){
            lanes[i].push_back(Car());
        }
}   
    // The below runs until all the cars in the queue pay the toll and leave 
    // the line. As you can see, we have a roll that gets passed into the
    // display function, and that decides whether or not a car is added to
    // the back of the line, or the front car leaves.
    for(int i = 0; i < NUM_TIME_INTERVALS; i++){
        int roll = rand() % TOTAL_CHANCE;
        displayTollBoothLine(lanes, round, roll);
        round++;
    }
}

// displayTollBoothLine() prints out the cars in the toll booth line,
// and if a car joined the line or left the line at that time interval.
// arguments: deque<Car>& tBL, int interval, int roll
// returns: nothing
void displayTollBoothLine(deque<Car> lanes[], int interval, int roll){ 
    for(int a = 0; a < NUM_LANES; a++){
    int laneLength = lanes[a].size();
    if(interval == 0){
        cout << "Initial Queue:\n";
        for(int i = 0; i < laneLength; i++){
            cout << "   ";
            lanes[i].print();
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
        else if(roll < (CAR_PAY_CHANCE + CAR_JOIN_CHANCE)){

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
}