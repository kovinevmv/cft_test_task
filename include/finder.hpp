#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "triangle.hpp"


/**
 * Class MaxTriangleFinder
 * 
 * Сlass has a special ```findMaxTriangleInFile``` to find the maximum
 * isosceles triangle in a file passed as agrument ```inputFule```. 
*/
class MaxTriangleFinder{

    Triangle maxTriangle;
    
public:
    /**
     * Default Constructor 
     */
    MaxTriangleFinder();

    /**
     * Method to find triangle
     */
    void findMaxTriangleInFile(std::ifstream& inputFule);

    // Getter
    Triangle getMaxIsoscelesTriangle();
};
