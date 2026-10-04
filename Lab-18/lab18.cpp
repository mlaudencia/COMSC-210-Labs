#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){

    vector<Movie> movies;
    string title, rev;
    double rating;

     ifstream inFile("movie-input.txt");

     if(!inFile){
        cout << "ERROR: Could not open data file! Check if it exists "
        << "in directory, then restart program!" << endl;
        return 1;
    }
}

