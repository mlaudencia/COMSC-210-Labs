#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

struct MovieRs{
    double rating;
    std::string review;
};

class Movie{
    private:
        std::string title;
        struct Node{
            MovieRs revAndRat;
            Node* next;
        };
        Node* head;
    public:
        Movie(std::string mT);
        void addRs(double rat, std::string& rev);
        void print();
        // Here, I added an avgRating() function, since when I got to making
        // my main and everything, calculating my average rating in main
        // felt like it was gonna make the code not as neat, so I just
        // decided to make this.
        double avgRating();
        ~Movie();
        Movie(const Movie& m);
        Movie& operator=(const Movie& m);
};

#endif