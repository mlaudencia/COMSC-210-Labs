#include "Movie.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

Movie::Movie(std::string mT){
    head = nullptr;
    title = mT;
}

void Movie::addRs(double rat, std::string& rev){
    Node* newNode = new Node();

    newNode->revAndRat.review = rev;
    newNode->revAndRat.rating = rat;

    newNode->next = head;
    head = newNode;
}

void Movie::print(){
    Node* current = head;
    std::cout << "Movie Title:" << title << std::endl;
    int count = 0;
    while(current != nullptr){
        std::cout << "   > Review " << ++count << ": " << 
        current->revAndRat.rating << ": " << 
        current->revAndRat.review << std::endl;
        current = current->next;
    }
}

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

Movie::~Movie(){
    Node* current = head;
    while(current != nullptr){
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}

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
