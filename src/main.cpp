#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

#include "point.hpp"
#include "triangle.hpp"


int main(int argc, char *argv[]){
    // Try to get input and output filenames from args
    try{
        std::string filenameInput = argv[1];
        std::string filenameOutput = argv[2];
    }
    catch(...){
        std::cerr << "Incorect args. Run program with 2 params: " << std::endl 
                  << "./main input.txt output.txt" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filenameInput = argv[1];
    std::string filenameOutput = argv[2];
    
    std::ifstream fileInput(filenameInput);
    if (fileInput.fail()){
        std::cerr << "Unable open input file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmpLine;
    Triangle maxTriangle;
    size_t currentIteration = 1;

    while (std::getline(fileInput, tmpLine)){
        std::istringstream iss(tmpLine);

        double x1, y1, x2, y2, x3, y3;
        if (!(iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            std::cerr << "Incorrect line #" << currentIteration 
                        << ". Can't read 6 coordinates. Skip" << std::endl;
        }

        Triangle triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
        if (triangle.isIsosceles()){
            double currentTriangeSquare = triangle.getSquare();
            if (maxTriangle.getSquare() <= currentTriangeSquare){
                maxTriangle = triangle;
            }
        }
    }
    fileInput.close();

    // TODO remove it 
    std::cout << "Max : " << maxTriangle.getSquare() << "\n";

    std::ofstream fileOutput(filenameOutput);
    if (fileOutput.fail()){
        std::cerr << "Unable open output file" << std::endl;
        return EXIT_FAILURE;
    }

    if (maxTriangle.getSquare() != 0.0){
        fileOutput << maxTriangle;
    }

    fileOutput.close();
    return EXIT_SUCCESS;
}