#!/bin/bash


if [ -z "$1" ];
then
    inputFile="input.txt"
else
    inputFile=$1
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
    count=`shuf -i 0-100 -n 1`
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


generateTriangles $inputFile
