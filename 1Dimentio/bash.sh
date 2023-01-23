#!/bin/bash

echo "Compiling..."
gcc -std=c99 -o monteCarlo monteCarlo.c

rm mc_error.dat

echo "Computing the integral"
i=1
for i in {1..30}
do
  ./monteCarlo $((2**i)) >> mc_error.dat
done
 
rm mc_error_all.dat
