/*
Jesús Horacio Rojas Cortés A01020026
Box class
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
    unsigned int color1;

public:
    Box();
    void setX(unsigned int _x){ x = _x; }
    void setY(unsigned int _y){ y = _y; }
    void setWidth(unsigned int _width){ width = _width; }
    void setHeight(unsigned int _height){ height = _height; }
    unsigned int getX(){ return x; }
    unsigned int getY(){ return y; }
    unsigned int getWidth(){ return width; }
    unsigned int getHeight(){ return height; }
};

Box::Box(){
    srand(time(NULL));
    x = rand() % 600 + 1;
    y = rand() % 600 + 1;
    width = rand() % 101;
    height = rand() % 101;

}

#endif
