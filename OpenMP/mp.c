// gcc -fopenmp foo.c
// export OMP_NUM_THREADS=4
// ./a.out

#include "omp.h"
#include <stdio.h>

int main()
{
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("hello(%d)",ID);
        printf("world(%d) \n",ID);
    }
}