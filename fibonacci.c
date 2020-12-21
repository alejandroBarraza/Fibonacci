#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/*
@author alejandro barraza
fibonacci sequence and factor.

try the code with
g++ -fopenmp fibonacci.c
//20 is the fibonacci number to calculate
time ./a.exe 20

*/



int fib(int n) {

   if (n<2)
      return n;

   else {
      int i, j;
#pragma omp task shared(i) if(n>30)//do it in parallel only if n is grather than 30.
      i=fib(n-1);
#pragma omp task shared(j) if(n>30)//do it in parallel only if n is grather than 30.
      j=fib(n-2);
#pragma omp taskwait //wait until sum.
      return i+j;

   
      
   }
}

/*
the function int fib(int n) may be replace in this way.

int fib(int n) {
   if (n<2)
      return n;
   else {
      int i, j;
#pragma omp task shared(j) if(n>30)//do it in parallel only if n is grather than 30.    
      j=fib(n-2);  //do fib (n-2) in parallel. 
      i=fib(n-1);
#pragma omp taskwait //wait until sum.
      return i+j;  
   }
}

*/



int main(int argc, char **argv){
   int n, result;
   char *a = argv[1];
   n = atoi(a);
   
   
#pragma omp parallel 
{
#pragma omp single
{  
         //calculate fibonacci number from F(0) to F(n)
         for (size_t i = 0; i <= n; i++)
         {
            result = fib(i);   
            printf("fibonacci(%d)"   "=%ld ==> ", i, result);
            
            //calcute the factor of fibonacci sequence
            int divide = 2;
            if (result < 6) {
               printf("%d", result);

            } else {
               while (result != 1) {

                     if (result % divide == 0) {
                        printf("%d ", divide );
                        result = result / divide ;

                        if (result != 1)
                           printf("x ");

                     } else {
                        divide++;
                     }
               }
            }
            printf("\n"); 
         }       
}
}   
}
