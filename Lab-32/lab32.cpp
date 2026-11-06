#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int DQ_INITAL_SIZE = 2;
const int TOTAL_CHANCE = 100;
const int CAR_PAY_CHANCE = 55;

int main(){
    srand(time(0));
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
    }
}