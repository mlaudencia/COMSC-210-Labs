#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

struct MovieRs{
    float rating;
    std::string review;
}

class Movie{
    private:
        std::string title;
        struct Node{
            MovieRs revAndRat;
        }
    public:
        void addRs(int rat, string rev);

};

#endif