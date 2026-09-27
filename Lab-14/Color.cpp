

#include "Color.h"
#include <iostream>

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

Color::Color(std::string name, int red, int green, int blue){
    color = name;
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