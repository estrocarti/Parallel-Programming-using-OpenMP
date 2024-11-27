#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "walltime.h"

int main(int argc, char *argv[]) {
    int N = 2000000000; // Size of the array
    double up = 1.00000001; // Growth factor
    int n;

    /* allocate memory for the recursion */
    double *opt = (double *)malloc((N + 1) * sizeof(double));
    if (opt == NULL) {
        perror("failed to allocate problem size");
        exit(EXIT_FAILURE);
    }

    double time_start = walltime();
    
    // Parallelize the loop with firstprivate and lastprivate clauses
    #pragma omp parallel for 
    for (n = 0; n <= N; ++n) {
        // Calculate Sn for this iteration without sharing Sn
        double local_Sn = 1.00000001 * pow(up, n); // Calculate Sn based on n
        opt[n] = local_Sn; // Store the result in the opt array
    }

    printf("Parallel RunTime  :  %f seconds\n", walltime() - time_start);
    
    // Calculate final value of Sn after all iterations
    double final_Sn = 1.00000001 * pow(up, N);
    printf("Final Result Sn   :  %.17g \n", final_Sn); 

    double temp = 0.0;
    for (n = 0; n <= N; ++n) {
        temp += opt[n] * opt[n]; // Calculate ||opt||^2_2
    }
    
    printf("Result ||opt||^2_2 :  %f\n", temp / (double)N);
    printf("\n");

    free(opt); // Free allocated memory
    return 0;
}
