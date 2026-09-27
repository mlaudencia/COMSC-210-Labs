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
        Movie();
        Movie(std::string sW, std::string title, int year);

        std::string getScreenWriter();
        std::string getTitle();
        int getYearReleased();

        void setScreenWriter(std::string sW);
        void setTitle(std::string title);
        void setYearReleased(int year);

        void printMovie();

};

#endif