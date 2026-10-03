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
        void addRs(double rat, std::string& rev);
        void print();
        ~Movie();
        Movie(const Movie& m);
        Movie& operator=(const Movie& m);
};

#endif