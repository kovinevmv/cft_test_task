#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "triangle.hpp"


class MaxTriangleFinder{
    Triangle maxTriangle;
    std::ifstream fileInput;
    
public:
    MaxTriangleFinder(std::ifstream& fileInput) : 
        maxTriangle(Triangle()) {
        fileInput.open(fileInput);
    };

    void findMaxTriangle(){
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

            Triangle currentTriangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
            if (currentTriangle.isIsosceles()){
                double currentTriangeSquare = currentTriangle.getSquare();
                if (maxTriangle.getSquare() <= currentTriangeSquare){
                    maxTriangle = currentTriangle;
                }
            }
        }
        fileInput.close();
    }

    Triangle getMaxIsoscelesTriangle(){
        return maxTriangle;
    }

}

