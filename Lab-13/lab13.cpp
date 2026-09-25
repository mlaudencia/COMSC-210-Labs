#include <iostream>
#include <fstream>
using namespace std;

const int NUM_STUDENTS = 150;

struct Student{
    int id;
    double grade;
};

void SelectionSort(Student* students, int NUM_STUDENTS);
void minScore(Student* students, int NUM_STUDENTS);
void maxScore(Student* students, int NUM_STUDENTS);
void meanScore(Student* students, int NUM_STUDENTS);
void sdScore(Student* students, int NUM_STUDENTS);

int main(){

    Student students[150];
    ifstream inFile("210-lab-13-grades.txt");

    if(!inFile){
        cout << "ERROR: Could not open data file!" << endl;
        return 1;
    }

     for(int i = 0; i < NUM_STUDENTS; ++i){
        inFile >> students[i].id >> students[i].grade;
     }

     inFile.close();
     cout << "Data read successfully!" << endl;
}

void SelectionSort(Student* students, int NUM_STUDENTS){
    for(int i = 0; i < NUM_STUDENTS - 1; i++){
        int smallIndex = i;
        Student temp;
        for(int j = i + 1; j < NUM_STUDENTS; j++){
            if(students[j].id < students[smallIndex].id){
                smallIndex = j;
            }
        }
        temp = students[i];
        students[i] = students[smallIndex];
        students[smallIndex] = temp;
        
    }
};

void minScore(Student* students, int NUM_STUDENTS){
    int smallScore = 0;
        for(int i = 1; i < NUM_STUDENTS; i++){
            if(students[i].grade < students[smallScore].grade)
                smallScore = i;
        }
    }
    cout << "Minimum score: " << students[smallScore].grade
    << " (Student ID: " << students[smallScore].id << ") " << endl;
};

void maxScore(Student* students, int NUM_STUDENTS){

};
void meanScore(Student* students, int NUM_STUDENTS){

};
void sdScore(Student* students, int NUM_STUDENTS){

};