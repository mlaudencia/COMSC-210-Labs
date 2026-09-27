
// Here, I include the Movie.h file, <iostream>, and <string>.
// I didn't think I needed to include <string> since I originally
// thought that <iostream> kind of indirectly included <string>,
// but apparently it is good practice to "include what you use",
// so I am going to try my best to start doing that.
#include "Movie.h"
#include <iostream>
#include <string>

// I make the movie constructor here, once again practicing not
// using the standard namespace and adding std:: to string parameters
// and functions for the below.
Movie::Movie(std::string sW, int year, std::string title){
    screenWriter = sW;
    movieTitle = title;
    yearReleased = year;
}

// Standard gets
std::string Movie::getScreenWriter(){
    return screenWriter;
}

std::string Movie::getMovieTitle(){
    return movieTitle;
}

int Movie::getYearReleased(){
    return yearReleased;
}

// Standard sets
void Movie::setScreenWriter(std::string sW){
    screenWriter = sW;
}

void Movie::setMovieTitle(std::string title){
    movieTitle = title;
}

void Movie::setYearReleased(int year){
    yearReleased = year;
}

void Movie::printMovie(){
    std::cout << "Movie Title: " << movieTitle << std::endl;
    std::cout << "    Year released: " << yearReleased << std::endl;
    std::cout << "    Screenwriter: " << screenWriter << std::endl;
}