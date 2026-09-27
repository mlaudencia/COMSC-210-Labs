

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

    // While I was writing this, I was wondering if the order
    // of the stuff in the external file mattered when putting
    // its values into the temp movie. Searching it up, apparently
    // it does a lot, so I changed the order to match the external
    // file.

    // I ended up having to change it from
    // while(inFile >> sW >> year >> title)
    // to the below, because there was a problem with reading in
    // spaced out strings compared to just one word. Searching up
    // and learning about it was tough, but definitely useful.
    while(true){
        // This makes sW the screenwriter, and if not, break. This
        // will be the thing that breaks the loop once all 4 movies
        // have been read in.
        if(!getline(inFile, sW)) break;
        // This reads in the year, and just in case there's nothing
        // to read in, break here. Same for the below. The difference
        // is that using inFile reads just the number, so the next time
        // getline() is used, it's basically reading an empty line. That's
        // why I use inFile.ignore() to ignore that empty line, and read the
        // next line, which is the one with the movie title.
        if(!(inFile >> year)) break;
        inFile.ignore();
        if(!getline(inFile, title)) break;
        // After that, like the lab instructions, we set it to a temp movie,
        // then push it back into movies.
        Movie temp(sW, year, title);
        movies.push_back(temp);
    }

    // After we're done with the external file, we close it for no memory
    // leaks, and then print that the data from it was successfully read in.
    inFile.close();
    cout << "Succesfully read in data file! " << endl;

    // Finally, we just used an enhanced for loop and print each movie out.
    for(Movie movie : movies){
        movie.printMovie();
    }

}