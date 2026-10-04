#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_MOVIES = 4;

int main(){

    srand(time(0));
    vector<Movie> movies;
    string title, rev;
    double rating;

     ifstream inFile("movie-input.txt");

     if(!inFile){
        cout << "ERROR: Could not open data file! Check if it exists "
        << "in directory, then restart program!" << endl;
        return 1;
    }

    movies.push_back(Movie("The Coming of Verity"));
    movies.push_back(Movie("The Return of Verity"));
    movies.push_back(Movie("Give Me My Toy Right Now!"));
    movies.push_back(Movie("Clark and Steve: Into the Minecraft Backrooms"));
}

