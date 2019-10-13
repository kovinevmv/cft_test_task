#include "point.hpp"

Point::Point(double x, double y) : x(x), y(y) {};

Point::Point () : Point(0.0, 0.0) {};

double Point::getX() const {
    return x;
}
double Point::getY() const {
    return y;
}

void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
    this->y = y;
}

double Point::distanceToPoint(const Point& other){
    return sqrt(pow((this->x - other.getX()), 2) +
                    pow(this->y - other.getY(),2));
}

std::ostream& Point::operator<<(std::ostream& os){
    return os << x << ' ' <<  y << std::endl;
}
