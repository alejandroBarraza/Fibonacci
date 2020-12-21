# Fibonacci
Fibonacci sequence and factor with openMP
this code can calcute the fibonacci sequence and factor in paraller using openMP.
 
# How to execute the code
the code can be executed with g++ or another compiler than support OpenMP. In this case was tested with g++

# Commands for test in G++
first go at yout current folder where is your code.
g++ -fopenmp fibonacci.c
optional(OMP_NUM_THREADS=6)
time ./a.exe (number of the fibonacci sequence to calculate) example: time ./a.exe 20 for F(0),F(1),F(2)...F(N)=20
