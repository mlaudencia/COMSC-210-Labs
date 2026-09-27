#pragma once
#ifndef COLOR_H
#define COLOR_H
#include <iostream>

class Color{
    private:
        int r;
        int g;
        int b;
        std::string color;
    public:
        Color();
        Color(int red, int green, int blue);
        Color(std::string name, int red, int green, int blue);

        int getName();
        int getR();
        int getG();
        int getB();

        void setR(int red);
        void setG(int green);
        void setB(int blue);

        void print1();
        void print2();

};


#endif