#pragma once
#include <math.h>
#include <iostream>


/*
 * Simple Point class
*/

class Point{
    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {};
    Point () : Point(0.0, 0.0) {};

    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }

    void setX(double x){
        this->x = x;
    }

    void setY(double y){
        this->y = y;
    }

    double distanceToPoint(const Point& other){
        return sqrt(pow((this->x - other.getX()), 2) +
                        pow(this->y - other.getY(),2));
    }
    
    std::ostream& operator<<(std::ostream& os){
        return os << x << ' ' <<  y << std::endl;
    }
};