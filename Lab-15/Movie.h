#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

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