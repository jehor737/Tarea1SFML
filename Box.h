/*
Jesús Horacio Rojas Cortés A01020026
Box class for use with the SFML
*/
#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Box {
private:
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
    unsigned int R, G, B;

public:
    Box();
    Box(unsigned int _x, unsigned int _y, unsigned int _width, unsigned int _height);
    void setX(unsigned int _x){ x = _x; }
    void setY(unsigned int _y){ y = _y; }
    void setWidth(unsigned int _width){ width = _width; }
    void setHeight(unsigned int _height){ height = _height; }
    unsigned int getX(){ return x; }
    unsigned int getY(){ return y; }
    unsigned int getWidth(){ return width; }
    unsigned int getHeight(){ return height; }
    unsigned int getRed(){ return R; }//R from RGB
    unsigned int getGreen(){ return G; }//G from RGB
    unsigned int getBlue(){ return B; }//B from RGB
};

Box::Box()//default new random box
{
    x = rand() % 800 + 1;
    y = rand() % 600 + 1;
    width = rand() % 101;
    height = rand() % 101;
    R = rand() % 256;
    G = rand() % 256;
    B = rand() % 256;
}
Box::Box(unsigned int _x, unsigned int _y, unsigned int _width, unsigned int _height)//Custom box, color still random
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    R = rand() % 256;
    G = rand() % 256;
    B = rand() % 256;
}

#endif
