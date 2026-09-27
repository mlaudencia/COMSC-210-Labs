
// Here, I include the Movie.h file, <iostream>, and <string>.
// I didn't think I needed to include <string> since I originally
// thought that <iostream> kind of indirectly included <string>,
// but apparently it is good practice to "include what you use",
// so I am going to try my best to start doing that.
#include "Movie.h"
#include <iostream>
#include <string>

Movie::Movie(std::string sW, std::string title, int year){
    screenWriter = sW;
    movieTitle = title;
    yearReleased = year;
}

std::string Movie::getScreenWriter(){
    return screenWriter;
}

std::string Movie::getMovieTitle(){
    return movieTitle;
}

int Movie::getYearReleased(){
    return yearReleased;
}

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