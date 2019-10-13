#pragma once
#include "point.cpp"
#include <iostream>


/*
 * Class describes gemeotry of Triangle
 * Lenght of sides: lengthAB, lengthBC, lengthAC 
 */
class Triangle{
    Point pointA;
    Point pointB;
    Point pointC;

    double lengthAB, lengthBC, lengthAC;
    bool isIsosceles_;

public:
    Triangle(const Point& a, const Point& b, const Point& c) : 
        pointA(a), pointB(b), pointC(c) {
        lengthAB = pointA.distanceToPoint(pointB);
        lengthBC = pointB.distanceToPoint(pointC);
        lengthAC = pointA.distanceToPoint(pointC);

        isIsosceles_ = checkIsIsosceles();
    };

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : 
            pointA(x1, y1), pointB(x2, y2), pointC(x3, y3) {};
    
    Triangle() : Triangle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {};

    double getSquare() const {
        double p = (lengthAB + lengthAC + lengthBC) / 2;
        double s = sqrt(p * (p - lengthAB) * (p - lengthAC) * (p - lengthBC));
        return s;
    }

    bool isIsosceles() const{
        return isIsosceles_;
    }

    Point getPointA() const {
        return pointA;
    }
    Point getPointB() const {
        return pointB;
    }
    Point getPointC() const {
        return pointC;
    }

    std::ostream& operator<<(std::ostream& os){
        return os << pointA.getX() << ' ' << pointA.getY() << ' '
                  << pointB.getX() << ' ' << pointB.getY() << ' ' 
                  << pointC.getX() << ' ' << pointC.getY() << std::endl;
    }
    

private:
    // Check Isosceles of Triangle by side pairwise comparison 
    bool checkIsIsosceles(){
        return isEqual(lengthAB, lengthAC) || 
               isEqual(lengthAB, lengthBC) || 
               isEqual(lengthAC, lengthBC);
    }

    // Compare double variables 
    bool isEqual(double a, double b, double epsilon = 0.001){
        return std::abs(a - b) < epsilon;
    }
};