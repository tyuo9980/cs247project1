#!/bin/bash

TESTOUTPUT='./testoutput'
TESTCASE='./testcase'

make clean
make

echo "please enter seed_min"
read min
echo "please enter seed_max"
read max

echo "please enter test case min, in the form of lol*"
read min_t
echo "please enter test case max, in the form of lol*"
read max_t

rm -r $TESTOUTPUT
mkdir $TESTOUTPUT

for ((i=$min; i<=$max; i++))
do
    for ((j=$min_t; j<=$max_t; j++))
    do
        echo "/****start test case $j with seed $i*****/"
        ./straights $i < $TESTCASE/cas$j > $TESTOUTPUT/o1$i$j
        ./sample $i < $TESTCASE/cas$j > $TESTOUTPUT/o2$i$j
        echo "test case $j finished"
    done
done

echo "/********************************compare restuls****************************************/"

for ((i=$min; i<=$max; i++))
do
        for ((j=$min_t; j<=$max_t; j++))
        do
                echo "/****comparing test case $j with seed $i*****/"
                diff -wiB $TESTOUTPUT/o1$i$j $TESTOUTPUT/o2$i$j
                echo "test case $j passed"
        done
done