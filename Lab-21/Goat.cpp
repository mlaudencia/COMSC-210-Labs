#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 15;
const int MAX_AGE = 20;
const int MIN_AGE = 1;

class Goat{
    private:
      int age;
      string name;
      string color;
      string names[ARRAY_SIZE] = {"Abel", "Baron", "Coby", "Darius", "Eobard",
        "Francisco", "Amy", "Bailey", "Cass", "Delilah", "Eleanor", "Fiona", 
        "Doron", "Isaac", "Pot"};
      string colors[ARRAY_SIZE] = {"Black", "White", "Green", "Blue", "Red",
         "Pink", "Purple", "Brown", "Beige", "Rainbow", "Orange", "Yellow",
         "Gray", "Violet", "Gold"};
    public:
        Goat(){
            age = (rand() % MAX_AGE) + 1;

        }
};