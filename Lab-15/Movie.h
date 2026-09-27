// Here, I use an include guard to make sure that the Movie.h file
// is processed only once.

#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

// Everything here is pretty straightforward with the lab instructions.
// The only thing I'd comment on is the movie constructor, since I had
// to change the order of those parameters before to match the order
// of the stuff in the external file that was gonna be read in.
class Movie{
    private:
        std::string screenWriter;
        std::string movieTitle;
        int yearReleased;
    public:
        Movie(std::string sW, int year, std::string title);

        std::string getScreenWriter();
        std::string getMovieTitle();
        int getYearReleased();

        void setScreenWriter(std::string sW);
        void setMovieTitle(std::string title);
        void setYearReleased(int year);

        void printMovie();

};

#endif