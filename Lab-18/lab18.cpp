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
const int MAX_RATING = 5;
const int MIN_RATING = 1;

int main(){

    srand(time(0));
    vector<Movie> movies;
    string title, rev;
    double rating;

     ifstream inFile("review-input.txt");

     if(!inFile){
        cout << "ERROR: Could not open data file! Check if it exists "
        << "in directory, then restart program!" << endl;
        return 1;
    }

    movies.push_back(Movie("The Coming of Verity"));
    movies.push_back(Movie("The Return of Verity"));
    movies.push_back(Movie("Give Me My Toy Right Now!"));
    movies.push_back(Movie("Clark and Steve: Into the Minecraft Backrooms"));

    for(int i = 0; i < NUM_MOVIES; i++){
        for(int j = 0; j < NUM_REVIEWS; j++){
            int randomRating = (rand() % MAX_RATING) + MIN_RATING;
            string review;

            getline(inFile, review);

            movies[i].addRs(randomRating, review);
        }
    }
    inFile.close();

    for(int i = 0; i < NUM_MOVIES; i++){
        movies[i].print();
    }
}

