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
        Color(int r, int g, int b);

        int getR();
        int getG();
        int getB();

        void setR(int r);
        void setG(int g);
        void setB(int b);

        void print();

};


#endif