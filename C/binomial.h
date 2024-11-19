

/**
 * This function calculates the number of ways to choose k elements from a set of n elements
 * without regard to the order of selection. It is defined as:
 * @param n The total number of elements.
 * @param k The number of elements to choose.
 * @return The binomial coefficient (n choose k).
 */
long choose(int n, int k);


long choose_memoization(int n, int k);

long inner_memoization(int n, int k, long **table);