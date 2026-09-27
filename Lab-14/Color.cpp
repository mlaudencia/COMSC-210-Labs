#include "Color.h"

Color::Color(){
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
}

int Color::getR(){
    return r;
}

int Color::getG(){
    return g;
}

int Color::getB(){
    return b;
}

void Color::setR(int red){
    r = red;
}

void Color::setG(int green){
    g = green;
}

void Color::setB(int blue){
    b = blue;
}

void Color::print(){
    cout << "Red value: " << r << endl;
    cout << "Green value: " << g << endl;
    cout << "Blue value: " << b << endl;
}