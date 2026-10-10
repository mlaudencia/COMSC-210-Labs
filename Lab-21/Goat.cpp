#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 15;
const int MAX_AGE = 20;
const int MIN_AGE = 1;
const int MAX_INDEX = 15;
const int MIN_INDEX = 1;

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
            age = (rand() % MAX_AGE) + MIN_AGE;
            name = names[(rand() % MAX_INDEX) + MIN_INDEX];
            color = colors[(rand() % MAX_INDEX) + MIN_INDEX];
        }
        Goat(int a, string n, string c){
            age = a;
            name = n;
            color = c;
        }
        void print(){
            cout << name << " (" << color << ", " << age << ")" << endl;
        }
        int getAge(){
            return age;
        }
        string getName(){
            return name;
        }
        string getColor(){
            return color;
        }
};