#pragma once
#include <iostream>

#include "point.hpp"

/*
 * Class Triangle
 * 
 * Сlass describes simple triangle geometry.
 */
class Triangle{
public:
    /**
     * Default Constructor 
     */
    Triangle();

    /**
     * Constructor by 3 points
     * 
     * @param a first point of triangle
     * @param b second point of triangle
     * @param c third point of triangle
     */
    Triangle(const Point& a, const Point& b, const Point& c);

    /**
     * Constructor by 6 coordinates
     * 
     * @param x1 - x coordinate of first point
     * @param y1 - y coordinate of first point
     * @param x2 - x coordinate of second point
     * @param y2 - y coordinate of second point
     * @param x3 - x coordinate of third point
     * @param y3 - y coordinate of third point
     */
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    /**
     * Calculate and return square of triangle
     * 
     * @return calculated square by Heron formula
     */
    double getSquare() const;

    /**
     * Is a triangle isosceles
     * 
     * If any two sides of the triangle are equal, then the triangle is isosceles
     * 
     * @return bool is  triangle isosceles
     */
    bool isIsosceles() const;

    // Getters for 3 points of triangle
    Point getPointA() const;
    Point getPointB() const;
    Point getPointC() const;

    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
    
private:
    // Triangle Isosceles Check
    bool checkIsIsosceles();

    // Points of triangle
    Point pointA;
    Point pointB;
    Point pointC;

    // The length of the sides of the triangle
    double lengthAB, lengthBC, lengthAC;

    // Is a triangle isosceles
    bool isIsosceles_;
};