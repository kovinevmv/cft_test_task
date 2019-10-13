#include "triangle.hpp"

// Compare double variables for equal
bool isEqual(double a, double b, double epsilon = 0.001){
    return fabs(a - b) < epsilon;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : 
    pointA(a), pointB(b), pointC(c) {
    lengthAB = pointA.distanceToPoint(pointB);
    lengthBC = pointB.distanceToPoint(pointC);
    lengthAC = pointA.distanceToPoint(pointC);

    isIsosceles_ = checkIsIsosceles();
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : 
        pointA(x1, y1), pointB(x2, y2), pointC(x3, y3) {}

Triangle::Triangle() : Triangle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {}

double Triangle::getSquare() const {
    double p = (lengthAB + lengthAC + lengthBC) / 2;
    double s = sqrt(p * (p - lengthAB) * (p - lengthAC) * (p - lengthBC));
    return s;
}

bool Triangle::isIsosceles() const {
    return isIsosceles_;
}

Point Triangle::getPointA() const {
    return pointA;
}
Point Triangle::getPointB() const {
    return pointB;
}
Point Triangle::getPointC() const {
    return pointC;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle){
    return os << triangle.getPointA().getX() << ' ' << triangle.getPointA().getY() << ' '
              << triangle.getPointB().getX() << ' ' << triangle.getPointB().getY() << ' '
              << triangle.getPointC().getX() << ' ' << triangle.getPointC().getY() << std::endl;
}

bool Triangle::checkIsIsosceles(){
    return isEqual(lengthAB, lengthAC) || 
            isEqual(lengthAB, lengthBC) || 
            isEqual(lengthAC, lengthBC);
}

