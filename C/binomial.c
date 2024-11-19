#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"

long choose(int n, int k) {
    // base
    if (k == 0 || n == k) {
        return 1;
    }

    // recursive call
    return choose(n-1, k) + choose(n-1, k-1);
}

long **table;

long choose_memoization_inner_function(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    }

    return choose_memoization_inner_function(n-1, k) + choose_memoization_inner_function(n-1, k-1);
}

long choose_memoization(int n, int k) {

    if (k == 0 || n == k) {
        return 1;
    }

    // create the memoization table of (n + 1) x (k + 1)
    table = (long ** ) malloc(sizeof(long *) * (n+1));
    if (table == NULL) {
        printf("ERROR\n");
        return 1;
    }
    // init rows
    for (int i = 0; i<n+1; i++) {
        table[i] = (long *) malloc(sizeof(long) * (k + 1));
        // check if alloc failed: free all alloced rows and table
        if (table[i] == NULL) {
            for (int x = 0; x<i; x++) {
                free(table[x]);
            }
            free(table);
            printf("ERROR\n");
            return 1;
        }
        // init rows with -1
        for (int j = 0; j<k+1; j++) {
            table[i][j] = -1;
        }
    }

    // we first access the table to see if the value is calculated already
    long calculated_value = table[n][k];
    if (calculated_value != -1) {
        return calculated_value; // the value is calcualted and can be returned
    } else {
        // calculate, store in table, return value
        long result = choose_memoization_inner_function(n, k);
        table[n][k] = result;
        return result;
    }

    // free the table
    for (int i = 0; i<n+1; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}

