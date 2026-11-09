// COMSC-210 | Lab 33 | Jeremy Laudencia

// Here, I included Car.h and <deque> per the lab instructions,
// <iostream> for outputs to the terminal, and 
// <cstdlib> and <ctime> for the random generation.
#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int DQ_INITIAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 46;
const int CAR_JOIN_CHANCE = 39;
const int EMPTY_LANE_JOIN_CHANCE = 50;

const int NUM_LANES = 4;
const int NUM_TIME_INTERVALS = 20;


void displayLanes(deque<Car> lanes[], int interval);

int main(){
    // This makes sure that the random numbers generated are actually random.
    srand(time(0));

    // Here, I make the deque array of size NUM_LANES< which is four.
    deque<Car> lanes[NUM_LANES];

    int round = 1;
    // After making the array, we use two for i loops to fill each lane with
    // two cars.
    for(int i = 0; i < NUM_LANES; i++){
        for(int j = 0; j < DQ_INITIAL_SIZE; j++){
            lanes[i].push_back(Car());
        }
    }   

    // This goes through each lane, and prints out the cars in them to show the
    // initial queue of each of the four lanes.
    cout << "Initial Queue:\n";
    for(int a = 0; a < NUM_LANES; a++){
        cout << "Lane: " << a+1 << endl;
        int laneLength = lanes[a].size(); 
        for(int i = 0; i < laneLength; i++){
            cout << "   ";
            lanes[a][i].print();
        }
    }
    
    // Unlike Lab 32, this now runs NUM_TIME_INTERVALS many times. Before, this
    // looped until the line was empty, but with four lanes, we just loop 20
    // times.
    for(int i = 0; i < NUM_TIME_INTERVALS; i++){
        displayLanes(lanes, round);
        round++;
    }
}

// displayTollBoothLine() prints out the cars in the toll booth line,
// and if a car joined the line or left the line at that time interval.
// arguments: deque<Car> lanes[], int interval
// returns: nothing

// Also in Lab 32, I made this so that the roll of the line was a parameter in
// the function, but since there is more than one lane now, I took it out and 
// now, there are rolls for each lane.
void displayLanes(deque<Car> lanes[], int interval){ 
    cout << "Time: " << interval << " Operation: \n";
    for(int a = 0; a < NUM_LANES; ++a){{
        cout << "Lane: " << a+1 << " ";
        if(lanes[a].empty()){
            // The below shows a 50/50 chance for a car to join an empty lane
            // or not, as per the Milestone 4 instructions.
            int emptyRoll = rand() % TOTAL_CHANCE;
            if(emptyRoll < EMPTY_LANE_JOIN_CHANCE){
                Car joining = Car();
                cout << "Joined: ";
                joining.print();
                lanes[a].push_back(joining);
            }
            else{
                cout << "Empty\n";
            }
            
            // After checking for the empty lanes, the below basically checks
            // the chances if a roll is from the 46% chance to pay and leave
            //, 39% chance to join a lane, and 15% chance to switch lanes.
            // The code below prints out the operation, or how a lane queue
            // changed, and then it prints ot the new queues below it.
        } else{
            int roll = rand() % TOTAL_CHANCE;
            if(roll < CAR_PAY_CHANCE){
                Car leaving = lanes[a].front();
                cout << "Paid:";
                leaving.print();
                lanes[a].pop_front();
            } else if(roll < CAR_PAY_CHANCE + CAR_JOIN_CHANCE){
            Car joining = Car();
            cout << "Joined: ";
            joining.print();
            lanes[a].push_back(joining);
        }
        else{
            // The below is the code for Milestone 5, at least the lane
            // switching support. The data structure operations are seen
            // through the lanes[a].pop_back(), lanes[a].pop_front(),
            // lanes[a].back(), etc.
            Car change = lanes[a].back();
            cout << "Switched Lanes: ";
            change.print();
            lanes[a].pop_back();
            int newLane = rand() % NUM_LANES;
            while(newLane == a){
                // This is a loop so that the lane the car switches to isn't
                // its old lane.
                newLane = rand() % NUM_LANES;
            }
            lanes[newLane].push_back(change);

        }
        }
    }
}
// Here is where the new queues of the lanes are printed.
    for(int a = 0; a < NUM_LANES; a++){
        cout << "Lane " << a+1 << " Queue:\n";
        int laneLength = lanes[a].size();
        if(laneLength == 0){
            cout << "    Empty\n";
        } else{
        for(int i = 0; i < laneLength; i++){
            cout << "    ";
            lanes[a][i].print();
        }
    }
}
}