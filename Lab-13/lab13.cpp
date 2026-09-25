// COMSC-210 | Lab 13 | Jeremy Laudencia

// Here, I included <iostream> to handle the cout statements,
// <fstream> to read and export data files,
// and <cmath> to use square root for standard deviation.
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// I made the NUM_STUDENTS a constant variable equal to 150,
// since that's how many lines were in the data file, and since
// I'm using a raw array and not a vector.
const int NUM_STUDENTS = 150;

struct Student{
    int id;
    double grade;
};

// Here, I make prototypes for each thing in the program requirements.
// I use Student* students so that I can access the actual values of
// students and not a copy of them.
void SelectionSort(Student* students, int NUM_STUDENTS);
void minScore(Student* students, int NUM_STUDENTS);
void maxScore(Student* students, int NUM_STUDENTS);
void meanScore(Student* students, int NUM_STUDENTS);
void medianScore(Student* students, int NUM_STUDENTS);
void sdScore(Student* students, int NUM_STUDENTS);

int main(){

    // Here, I make an array of size NUM_STUDENTS of type Student,
    // then add the contents of the data file into the array by line.
    Student students[NUM_STUDENTS];
    ifstream inFile("210-lab-13-grades.txt");

    if(!inFile){
        cout << "ERROR: Could not open data file!" << endl;
        return;
    }

     for(int i = 0; i < NUM_STUDENTS; ++i){
        inFile >> students[i].id >> students[i].grade;
     }

     inFile.close();
     cout << "Data read successfully!" << endl;

     cout << "Read " << NUM_STUDENTS << " student records" << endl;

     // After reading the contents of the data file, we sort them by
     // ascending ID, and then export it as another data file.
     SelectionSort(students, NUM_STUDENTS);
     outputSortedStudents(students, NUM_STUDENTS, "210-lab-13-grades-sorted.txt");

     // The below just prints out the statistics of the summary,
     // which includes all the stuff in the program requirements.
     cout << " --- Summary Statistics ---" << endl;
     minScore(students, NUM_STUDENTS);
     maxScore(students, NUM_STUDENTS);
     meanScore(students, NUM_STUDENTS);
     medianScore(students, NUM_STUDENTS);
     sdScore(students, NUM_STUDENTS);
}


// SelectionSort() takes in an array and its size, and sorts it by
// ascending ID's.
// arguments: Student* students, int NUM_STUDENTS
// returns: nothing
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

// maxScore() takes in an array and its size, and prints what student
// had the smallest score and their ID. 
// arguments: Student* students, int NUM_STUDENTS
// returns: nothing
void minScore(Student* students, int NUM_STUDENTS){
    int smallScore = 0;
        for(int i = 1; i < NUM_STUDENTS; i++){
            if(students[i].grade < students[smallScore].grade){
                smallScore = i;
        }
    }
    cout << "Minimum score: " << students[smallScore].grade
    << " (Student ID: " << students[smallScore].id << ") " << endl;
};

// maxScore() takes in an array and its size, and prints what student
// had the largest score and their ID. 
// arguments: Student* students, int NUM_STUDENTS
// returns: nothing
void maxScore(Student* students, int NUM_STUDENTS){
    int highScore = 0;
        for(int i = 1; i < NUM_STUDENTS; i++){
            if(students[i].grade > students[highScore].grade){
                highScore = i;
        }
    }
    cout << "Maximum score: " << students[highScore].grade
    << " (Student ID: " << students[highScore].id << ") " << endl;
};

// findMeanScore() takes in an array and its size, and finds the
// mean of the array, adding all its values and dividing it by size.
// arguments: Student* students, int NUM_STUDENTS
// returns: nothing
double findMeanScore(Student* students, int NUM_STUDENTS){
    double total = 0;
    for(int i = 0; i < NUM_STUDENTS; i++){
        total += students[i].grade;
    }
    return total / NUM_STUDENTS;
};

// meanScore() takes in an array and its size, and prints what the
// mean of all student scores is.
// arguments: Student* students, int NUM_STUDENTS
// returns: nothing
void meanScore(Student* students, int NUM_STUDENTS){
    double meanScore = findMeanScore(students, NUM_STUDENTS);
    cout << "Mean score: " << meanScore << endl;
}

// medianScore() takes in an array and its size, and prints the ID's 
// of the student or students who were in the middle of the array.
// arguments: Student* students, int NUM_STUDENTS
// returns: nothing
void medianScore(Student* students, int NUM_STUDENTS){
    double median = 0;
    if(NUM_STUDENTS % 2 == 1){
        int middle = NUM_STUDENTS/2;
        median = students[middle].grade;

        cout << "Median score: " << median << " (Student ID: " 
        << students[middle].id << ") " << endl;
    }
    else{
        int middle1 = (NUM_STUDENTS / 2) - 1;
        int middle2 = (NUM_STUDENTS / 2);
        median = (students[middle1].grade + students[middle2].grade) / 2.0;

        cout << "Median score: " << median << " (Student IDs: " 
        << students[middle1].id << " " << students[middle2].id << ") " << endl;
    }
}

void sdScore(Student* students, int NUM_STUDENTS){
    double sd = 0;
    double total = 0;
    double mean = findMeanScore(students, NUM_STUDENTS);
    for(int i = 0; i < NUM_STUDENTS; i++){
        total = (students[i].grade - mean);
        sd += total * total;
    }
    cout << "Standard Deviation of Scores: " << sqrt(sd/NUM_STUDENTS) << endl;
}

void outputSortedStudents(Student* students, int NUM_STUDENTS, string fileName){
    ofstream outFile(fileName);

    if(!outFile.is_open()){
        cout << "ERROR: Could not open file for writing!" << endl;
        return;
    }

    for(int i = 0; i < NUM_STUDENTS; i++){
        outFile << students[i].id << " " << students[i].grade << endl;
    }
    
    outFile.close();

    cout << "Sorted results written to " << fileName << endl;
}
