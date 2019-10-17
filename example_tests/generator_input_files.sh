#!/bin/bash

if [ "$1" == "--help" ] || [ "$1" == "-h" ];
then
    echo "Script for generating list of triangles in format 'X X X X X X' - X is double value."
    echo "Сoordinates of each triangle are in [0,100]. One special triangle with an area 500 000 is added to each file so that its area is maximum in list."
    echo ""
    echo "Usage:"
    echo "First argument: output file (default - triangles.txt)"
    echo "Second argument: number of triangles (default - random value in [0,100])"
    echo ""
    echo "Examples of usage:"
    echo " ./generator_input_files.sh myfile.txt 1000"
    echo " ./generator_input_files.sh"
    exit 0
fi

if [ -z "$1" ];
then
    inputFile="triangles.txt"
else
    inputFile=$1
fi

if [ -z "$2" ];
then
    numOfTriangles=`shuf -i 1-100 -n 1`
else
    numOfTriangles=$2
fi

generateTriangle()
{
    for (( i=0; i<3; i++ ))
    do
        x=`shuf -i 0-100 -n 1`
        y=`shuf -i 0-100 -n 1`
        echo -en "$x $y " >> $1
    done
    echo -en "\n" >> $1
}

generateMaxIsoscelesTriangle()
{
    echo -e "1000 0 0 1000 0 0" >> $1
}

generateTriangles()
{
    count=$numOfTriangles
    random_pose=`shuf -i 0-$count -n 1`

    for (( j=0; j<$count; j++ ))
    do
        if [[ $j == $random_pose ]]
        then
            generateMaxIsoscelesTriangle $inputFile
        else
            generateTriangle $inputFile
        fi
    done
}


echo -n > $inputFile
generateTriangles $inputFile
