#include "Movie.h"
#include <string>
#include <iostream>

void Movie::addRs(double rat, std::string& rev){
    Node* newNode = new Node();

    newNode->revAndRat.review = rev;
    newNode->revAndRat.rating = rat;

    newNode->next = head;
    head = newNode;
}

void Movie::print(){
    Node* temp = new Node();
    while(temp->next != nullptr){
        
    }
}