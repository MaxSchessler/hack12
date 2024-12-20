/**
 * Author: Max Schessler
 * Date: 2024-11-19
 * 
 * This file holds method testing/benchmarking for my binomial recursive functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binomial.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage <program> <n> <k>\n");
        return -1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    if (n == 0 || k == 0) {
        printf("%s or %s not valid\n", argv[1], argv[2]);
        return 1;
    }

    if (k > n) {
        printf("Invalid Input k cannot be greater than n.\n");
        return 1;
    }

    clock_t start, end;
    long result;
    double execution_time;


    // /*** Benchmark the regular recursive function call and output results */
    // start = clock();  // start time
    // result = choose(n, k);  // call function
    // end = clock(); // get end time
    // execution_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // calculate time in milliseconds
    // printf("Result (Regular):  %ld\nTime: %f milliseconds\n", result, execution_time);
    // /*** Benchmark the regular recursive function call and output results */

    /*** Benchmark the memoization recursive function call and output results */   
    initialize_table(n, k); 

    start = clock();
    result = choose_memoization(n, k);
    end = clock();
    execution_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // calclulate time in milliseconds
    printf("Result (Memoization): %ld\nTime: %f milliseconds\n", result, execution_time);

    freeTable(n, k);
    /*** Benchmark the memoization recursive function call and output results */    
    


    return 0;
}