#pragma once
#ifndef COLOR_H
#define COLOR_H
#include <iostream>

using namespace std;

class Color{
    private:
        int r;
        int g;
        int b;
    public:
        Color();
        Color(int red, int green, int blue);

        int getR();
        int getG();
        int getB();

        void setR(int red);
        void setG(int green);
        void setB(int blue);

        void print();

};


#endif