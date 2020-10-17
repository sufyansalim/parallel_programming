#include "omp.h"
#include <stdio.h>

static long num_steps = 100000; double step;
int main ()
{ int i; double x, pi, sum = 0.0;
 step = 1.0/(double) num_steps;
 #pragma omp parallel num_threads(4)
 {
     double x;
     double time1 =  omp_get_wtime();
     #pragma omp for reduction(+:sum) schedule(static,1) 
      for (i=0;i< num_steps; i++){

      x = (i+0.5)*step;
      sum = sum + 4.0/(1.0+x*x);
    }
     double time2 =  omp_get_wtime() - time1;
    printf("time = %f \n",(time1-time2)/1000000.0);
 }

 pi = step * sum;
 printf("PI = (%f)",pi);
}
