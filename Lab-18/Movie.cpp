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

Movie::~Movie(){
    Node* current = head;
    while(current != nullptr){
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}