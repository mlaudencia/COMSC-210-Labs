#include "Movie.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Movie() creates a new movie.
// arguments: std::string mT, the movie title
// returns: nothing
Movie::Movie(std::string mT){
    head = nullptr;
    title = mT;
}

// addRs() adds a review and a rating to a movie.
// arguments: double rat, the rating, std::string& rev, the review
// returns: nothing
void Movie::addRs(double rat, std::string& rev){
    Node* newNode = new Node();

    newNode->revAndRat.review = rev;
    newNode->revAndRat.rating = rat;

    newNode->next = head;
    head = newNode;
}

// print() prints out the title, reviews, ratings, and avg rating of a movie
// arguments: none
// returns: nothing
void Movie::print(){
    Node* current = head;
    std::cout << "Movie Title:" << title << std::endl;
    int count = 0;
    while(current != nullptr){
        std::cout << "   > Review " << ++count << ": " << 
        std::fixed << std::setprecision(1) <<
        current->revAndRat.rating << ": " << 
        current->revAndRat.review << std::endl;
        current = current->next;
    }
    std::cout << "   > Average Rating: " << 
        std::fixed << std::setprecision(1) << 
        avgRating() << std::endl;
}

// avgRating() calculates the average rating of a movie.
// arguments: none
// returns: ratingTotal/count, a double for the avg rating of a movie
double Movie::avgRating(){
    Node* current = head;
    int count = 0;
    double ratingTotal = 0.0;
    if(current == nullptr){
        return 0;
    }
    while(current != nullptr){
            ratingTotal += current->revAndRat.rating;
            count++;
            current = current->next;
    }
    return (ratingTotal/count);
}

// ~Movie() deletes the data in a movie to free up memory.
// arguments: none
// returns: nothing
Movie::~Movie(){
    Node* current = head;
    while(current != nullptr){
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}

// Movie(const Movie& m) deep copies a movie and its reviews.
// arguments: const Movie& m
// returns: nothing
Movie::Movie(const Movie& m){
    if(m.head == nullptr){
            head = nullptr;
            return;
        }
    
    title = m.title;
    head = new Node();
    head->revAndRat.rating = m.head->revAndRat.rating;
    head->revAndRat.review = m.head->revAndRat.review;

    Node* current = m.head->next;
    Node* tail = head;

    while(current != nullptr){
        Node* copyNode = new Node();
        copyNode->revAndRat.rating = current->revAndRat.rating;
        copyNode->revAndRat.review = current->revAndRat.review;
        tail->next = copyNode;
        tail = copyNode;
        current = current->next;
    }
    tail->next = nullptr;
}

    // Continue the copy assingnment and main tomorrow

// operator=() copies one movie to another using an already existing movie.
// arguments: const Movie& m
// returns: a reference to the new copied movie
Movie& Movie::operator=(const Movie& m){
    if(this == &m){
        return *this;
    }
        Node* current = head;
    
    while(current != nullptr){
        Node* temp = current->next;
        delete current;
        current = temp;
    }
        head = nullptr;

    if(m.head == nullptr){
        return *this;
    }
    
    title = m.title;
    head = new Node();
    head->revAndRat.rating = m.head->revAndRat.rating;
    head->revAndRat.review = m.head->revAndRat.review;

    current = m.head->next;
    Node* tail = head;

    while(current != nullptr){
        Node* copyNode = new Node();
        copyNode->revAndRat.rating = current->revAndRat.rating;
        copyNode->revAndRat.review = current->revAndRat.review;
        tail->next = copyNode;
        tail = copyNode;
        current = current->next;
    }
    tail->next = nullptr;

    return *this;
    }
