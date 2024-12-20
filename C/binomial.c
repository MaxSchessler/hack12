/**
 * Author: Max Schessler
 * Date: 2024-11-19
 * 
 * This file holds method definitions for my binomial recursive functions.
 */

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

long **table = NULL;



void initialize_table(int n, int k) {
    n++;
    k++;
    table = (long **) malloc(sizeof(long *) * n);
    if (table == NULL) {
        printf("ERROR allocating memory for table\n");
        exit(1);
    }

    for (int i = 0; i<n; i++) {
        table[i] = (long *) calloc(k, sizeof(long));
        if (table[i] == NULL) {
            for (int x=0; x<i; x++) {
                free(table[x]);
            }
            free(table);
            printf("ERROR allocating memory for row %d in table.\n", i);
            exit(1);
        }
    }
}


void freeTable(int n, int k) {

    int count = 0;

    // count how many items are in this table that aren't 0
    for (int i =0; i<n+1; i++) {
        for (int j=0; j<k+1; j++) {
            if (table[i][j] == 0){
                count ++;
            }
        } 

        free(table[i]);
    }   
    free(table);
    printf("Numbers in the cache: %d\n", count);
}

long choose_memoization(int n, int k) {
    // base
    if (k == 0 || n == k) {
        return 1;
    } else if (table[n][k] != 0) {
        return table[n][k];
    } else {
        long result = choose_memoization(n-1, k) + choose_memoization(n-1, k-1);
        table[n][k] = result;
        return result;
    }
}
