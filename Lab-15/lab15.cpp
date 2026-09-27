#include "Movie.h"
#include "Movie.cpp"
#include <fstream>
#include <vector>
using namespace std;

int main(){

    // Here, I sort of defaulted to something like the below
    // vector<Movie>* movies = new vector<Movie>;
    // I think it is because we've been using dynamic arrays
    // and vectors in the past labs, but since we don't have 
    // to in this one, I just made a regular vector on the heap.
    // Now, I don't need to delete anything at the end of main!
    // Woo!
    vector<Movie> movies;
    string title, sW;
    int year;

    ifstream inFile("movie-input.txt");

     if(!inFile){
        cout << "ERROR: Could not open data file! Check if it exists "
        << "in directory, then restart program!" << endl;
        return 1;
    }

    while(inFile >> title >> sW >> year){
        Movie temp(sW, title, year);
        movies.push_back(temp);
    }

    inFile.close();

    Movie temp();
}