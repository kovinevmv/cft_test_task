#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "triangle.hpp"


void findTriangleWithMaxSquare(std::ifstream& fileInput, std::ofstream& fileOutput){
    std::string tmpLine;
    Triangle maxTriangle;
    size_t currentIteration = 0;

    while (std::getline(fileInput, tmpLine)){
        currentIteration++;

        std::istringstream iss(tmpLine);

        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
        if (!(iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            std::cerr << "Incorrect line #" << currentIteration 
                        << ". Can't read coordinates. Skip line" << std::endl;
            continue;
        }

        Triangle triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
        if (triangle.isIsosceles()){
            double currentTriangeSquare = triangle.getSquare();
            if (maxTriangle.getSquare() <= currentTriangeSquare){
                maxTriangle = triangle;
            }
        }

    }

    // TODO remove it 
    std::cout << "Max : " << maxTriangle.getSquare() << "\n";

    if (maxTriangle.getSquare() != 0.0){
        fileOutput << maxTriangle;
    }

}
