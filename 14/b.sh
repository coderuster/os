#!/bin/bash

read -p "Enter the value of n: " n
sum=0

for ((i = 1; i <= n; i++)); do
    read -p "Enter number $i: " num
    sum=$((sum + num))
done

echo "Sum of $n numbers is: $sum"
