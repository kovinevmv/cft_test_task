#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include "geometry/triangle.cpp"
#include "geometry/point.cpp"


int main(int argc, char *argv[]){

    try{
        std::string filenameInput = argv[1];
        std::string filenameOutput = argv[2];
    }
    catch(...){
        std::cout << "Incorect input args\n";
        return EXIT_FAILURE;
    }
    std::string filenameInput = argv[1];
    std::string filenameOutput = argv[2];
    
    std::ifstream fileInput(filenameInput);
    if (fileInput.fail()){
        std::cout << "Unable open input file\n";
        return EXIT_FAILURE;
    }

    std::string line;
    
    Triangle maxTriangle;

    while (std::getline(fileInput, line)){
        std::istringstream iss(line);
        double x1, y1, x2, y2, x3, y3;
        if (!(iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            std::cout << "Incorrect line. Skip\n";
            break;
        }
        Triangle triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
        if (triangle.isIsosceles()){
            double currentTriangeSquare = triangle.getSquare();
            if (maxTriangle.getSquare() <= currentTriangeSquare){
                maxTriangle = triangle;
            }
        }
    }

    std::cout << "Max : " << maxTriangle.getSquare() << "\n";

    std::ofstream fileOutput(filenameOutput);
    if (maxTriangle.getSquare() != 0.0){
        fileOutput << maxTriangle;
    }
    return EXIT_SUCCESS;
}