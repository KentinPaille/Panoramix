#!/bin/bash

# Test case 1: Valid input
echo "Test Case 1:"
output=$(./panoramix 5 10 3 2)
expected_output=""
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test case 2: Negative values
echo "Test Case 2:"
output=$(./panoramix 5 -10 3 2)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>
Values must be >0."
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test case 3: Insufficient refill
echo "Test Case 3:"
output=$(./panoramix 5 10 3 0)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>
Values must be >0."
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test case 4: Insufficient refill
echo "Test Case 4:"
output=$(./panoramix 0 10 3 5)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>
Values must be >0."
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi


# Test case 5: Insufficient refill
echo "Test Case 5:"
output=$(./panoramix 10 10 -885 5)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>
Values must be >0."
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test case 6: Insufficient refill
echo "Test Case 6:"
output=$(./panoramix)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>"
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test case 7: Insufficient refill
echo "Test Case 7:"
output=$(./panoramix 847 84 847 747 47 848)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>"
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test case 8: Insufficient refill
echo "Test Case 8:"
output=$(./panoramix 847 84 847 e)
expected_output="USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> <nb_refills>
Values must be >0."
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi