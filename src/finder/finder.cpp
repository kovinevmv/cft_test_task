#include "finder.hpp"

MaxTriangleFinder::MaxTriangleFinder() : maxTriangle(Triangle()) {};

void MaxTriangleFinder::findMaxTriangleInFile(std::ifstream& inputFule){
    std::string tmpLine;
    size_t currentIterationIndex = 0;

    while (std::getline(inputFule, tmpLine)){
        currentIterationIndex++;

        std::istringstream iss(tmpLine);
        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
        
        // Read 3 coordinates (x, y) of triangle
        if (!(iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            // Skip line if data is incorrect
            //std::cerr << "Incorrect line #" << currentIterationIndex 
            //            << ". Can't read coordinates by mask: X X X X X X, where X - num in any type. Skip line" << std::endl;
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
    inputFule.close();
}

Triangle MaxTriangleFinder::getMaxIsoscelesTriangle(){
    return maxTriangle;
}

