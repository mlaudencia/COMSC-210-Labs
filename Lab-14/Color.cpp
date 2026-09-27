// Here, I include the h file, and then <iostream>, because
// I actually use cout statements in this file, so I need it.
#include "Color.h"
#include <iostream>

// Here's my default constructor that basically just makes the
// color black.
Color::Color(){
    r = 0;
    g = 0;
    b = 0;
}

// Another constructor, as you can see, just taking in the rgb values.
Color::Color(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
}

// Same thing as above, just including the name. I feel like making
// the color name called color is a bit bad since the class is also
// called color, so I will try not to use the same names for a variable
// and the class in the future.
Color::Color(std::string name, int red, int green, int blue){
    color = name;
    r = red;
    g = green;
    b = blue;
}

// Everything else below is pretty self-explanatory, just my 
// gets and sets, and then the two different version of print.

std::string Color::getName(){
    return color;
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

void Color::setColor(std::string name){
    color = name;
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

void Color::print1(){
    std::cout << "    Red value: " << r << std::endl;
    std::cout << "    Green value: " << g << std::endl;
    std::cout << "    Blue value: " << b << std::endl;
}

void Color::print2(){
    std::cout << "Color name: " << color << std::endl;
    std::cout << "    Red value: " << r << std::endl;
    std::cout << "    Green value: " << g << std::endl;
    std::cout << "    Blue value: " << b << std::endl;
}