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
const int DQ_INITIAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 55;

void displayTollBoothLine(deque<Car>& tBL, int interval, int roll);

int main(){
    srand(time(0));

    int round = 0;
    // Here, I make the tollBoothLine, and then below that, I make the initial
    // queue of the line.
    deque<Car> tollBoothLine;

    for(int i = 0; i < DQ_INITIAL_SIZE; i++){
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

// displayTollBoothLine() prints out the cars in the toll booth line,
// and if a car joined the line or left the line at that tim interval.
// arguments: deque<Car>& tBL, int interval, int roll
// returns: nothing
void displayTollBoothLine(deque<Car>& tBL, int interval, int roll){ 
    // I actually had a little bit of trouble with this function. At first,
    // I made my deque parameter constant since I intended to change the line
    // in main without a function, but there was an error with calling print()
    // for a car. I wasn't sure why, since I was just printing the info of the
    // car through its function in its h file, but it turns out if the function
    // isn't declared as a const function, then the program thinks that calling
    // it might change something, resulting in the error with my parameter
    // since there was a mismatch: const vs not-const despite not changing
    // anything.

    // After that, I changed it so tBL wasn't constant, and my code ran for a
    // bit, but then I ran into another error regarding front(). If a car was
    // to pay its toll and leave, my code would still check for tBL.front()
    // even when the line was empty, resulting in an error. I just had to make
    // sure that I wasn't popping the car from the front out before calling
    // tBL.front(), so I worked around that.
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
            // Because the previous if statement checks if the roll is 
            // in that 55% chance to pay and leave, I don't need to use
            // another chance here, since anything else would be the 45%
            // chance for another car to join the line.
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