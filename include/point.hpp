#pragma once
#include <math.h>
#include <iostream>

/**
 * Class Point
 * 
 * Сlass describes simple point geometry.
*/
class Point{
    double x;
    double y;

public:
    /**
     * Default Constructor 
     */
    Point ();
    
    /**
     * Constructor with 2 params
     * 
     * @param x x-coordinate of point
     * @param x y-coordinate of point
     */
    Point(double x, double y);


    // Getters x,y
    double getX() const;
    double getY() const;

    // Setters x,t
    void setX(double x);
    void setY(double y);

    /**
     * Calculate distance between 2 points
     * 
     * @param other point to which you need to find distance
     * from this
     */

    double distanceToPoint(const Point& other);
    
    std::ostream& operator<<(std::ostream& os);
};