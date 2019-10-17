#include <fstream>

#include "logic/logic.cpp"
#include "point.hpp"
#include "triangle.hpp"
#include "logic/logic.cpp"


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
    
    std::ifstream fileInput;
    fileInput.open(filenameInput, std::ios_base::in);
    if (fileInput.fail()){
        std::cerr << "Unable open input file" << std::endl;
        return EXIT_FAILURE;
    }

    std::ofstream fileOutput(filenameOutput);
    if (fileOutput.fail()){
        std::cerr << "Unable open output file" << std::endl;
        return EXIT_FAILURE;
    }

    MaxTriangleFinder maxTriangleFinder(fileInput);
    maxTriangleFinder.findMaxTriangle();
    Triangle maxTriangle = maxTriangleFinder.getMaxIsoscelesTriangle();
    
    if (maxTriangle.getSquare() != 0.0){
        fileOutput << maxTriangle;
    }
    fileOutput.close();
    return EXIT_SUCCESS;
}