// Here, I use an include guard, and then define Color.h and make
// its private and public members depending on what I saw in the
// assignment instructions, aside from some things here that I
// will comment on.
#pragma once
#ifndef COLOR_H
#define COLOR_H
// Before, I included <iostream> and was using namespace std;, but
// I know that's bad to practice with h files, especially the using
// namespace std;, so I took it out, and changed <iostream> with
// string so that strings could still be handled. I added this,
// because I wanted to output the name of the color instead of 
// hardcoding it in with couts in my main file.
#include <string>

class Color{
    private:
        // Here, I make the private member variables for red, green,
        // and blue, as well as string color for the name. I don't
        // really like adding std:: in front of stuff, but I think
        // it is better to practice it so that in the future, I don't
        // make a habit of having errors with using namespace std;.
        int r;
        int g;
        int b;
        std::string color;
    public:
        // Here, I make three constructors for Color: one default,
        // one that takes in the rgb values, and then one that takes
        // in rgb values and the name of the color. I just thought
        // having that name included in the print would make it look
        // nicer.
        Color();
        Color(int red, int green, int blue);
        Color(std::string name, int red, int green, int blue);

        // Standard gets here
        std::string getName();
        int getR();
        int getG();
        int getB();

        // Standard sets
        void setColor(std::string name);
        void setR(int red);
        void setG(int green);
        void setB(int blue);

        // Here are my two versions of print, one that just prints out
        // the rgb values of a color, and then one that does the same
        // thing but adds its name alongside those just for nicer 
        // presentation.
        void print1();
        void print2();

};


#endif