/**
 * Author: Max Schessler
 * Date: 2024-11-19
 * 
 * This file holds method declarations for my binomial recursive functions.
 */

/**
 * This function calculates the number of ways to choose k elements from a set of n elements
 * without regard to the order of selection. It is defined as:
 * @param n The total number of elements.
 * @param k The number of elements to choose.
 * @return The binomial coefficient (n choose k).
 */
long choose(int n, int k);

/**
 * This function calculates the binomial coefficient, which represents the number
 * of ways to choose k items from n items without regard to order. It uses memoization
 * to store previously computed values for efficiency.
 *
 * @param n The total number of items.
 * @param k The number of items to choose.
 * @return The binomial coefficient C(n, k).
 */
long choose_memoization(int n, int k);

/**
 * This function sets up the memoization table that will be used to store intermediate
 * results of binomial coefficient calculations. It should be called before any calls
 * to choose_memoization().
 *
 * @param n The total number of items.
 * @param k The number of items to choose.
 */
void initialize_table(int n, int k);

/**
 * This function releases the memory that was allocated for the memoization table.
 * It should be called when binomial coefficient calculations are complete to avoid
 * memory leaks.
 *
 * @param n The total number of items.
 */
void freeTable(int n);
