// COMSC-210 | Lab 18 | Jeremy Laudencia

// Here, I included <iostream> to handle couts, <fstream> for external files,
// <string> since I use strings in this program, <vector> to hold my movies,
// and <cstidlib> and <ctime> to generate random ratings.
// I also included Movie.h, and previously, Movie.cpp. I know Movie.cpp is bad to add in my
// main file, but I was having compilation errors, and instead of typing some
// code into my terminal everytime, I was just able to run without debugging
// if I included Movie.cpp, so I removed it after using that for convenience.
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_MOVIES = 4;
const int NUM_REVIEWS = 3;
const int MAX_RATING_SCALED = 41;
const int MIN_RATING_SCALED = 10;
const double SCALE_FACTOR = 10.0;

int main(){

    // The srand(time(0)) initializes my random number generator for ratings.
    srand(time(0));
    vector<Movie> movies;
    string title, rev;
    double rating;

    // Read in my external file, and give an error if it can't be read in
     ifstream inFile("review-input.txt");

     if(!inFile){
        cout << "ERROR: Could not open data file! Check if it exists "
        << "in directory, then restart program!" << endl;
        return 1;
    }

    // Make my four movies
    movies.push_back(Movie("The Coming of Verity"));
    movies.push_back(Movie("The Return of Verity"));
    movies.push_back(Movie("Give Me My Toy Right Now!"));
    movies.push_back(Movie("Clark and Steve: Into the Minecraft Backrooms"));

    // Put in 3 reviews for each movie in the movies vector. One thing that
    // was a bit tough here was making my ratings double, and I had to 
    // search up how to use static_cast<double>().
    for(int i = 0; i < NUM_MOVIES; i++){
        for(int j = 0; j < NUM_REVIEWS; j++){
            double randomRating = ((rand() % MAX_RATING_SCALED) + MIN_RATING_SCALED) / SCALE_FACTOR;
            string review;

            getline(inFile, review);

            movies[i].addRs(randomRating, review);
        }
    }
    inFile.close();

    // Print all the movies and their reviews, ratings, and average rating.
    for(int i = 0; i < NUM_MOVIES; i++){
        movies[i].print();
    }
}

