/**
 * Author Max Schessler
 * Date: 2024-11-19
 * 
 * This file holds functions for recursive callculation of the choose function.
 * Also holds main method in which it tests my recursive functions and benchmarks them.
 */

package unl.soc;

import java.math.BigInteger;
import java.util.Map;


import java.util.HashMap;


public class Binomial {

    public static Map<Pair<Integer, Integer>, BigInteger> memoizationTable = new HashMap<>();

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage 'java Binomial.java <n> <k> ");
            System.exit(1);
        }

        try {
            Integer.parseInt( args[0] );
            Integer.parseInt( args[1] );
        } catch( Exception e ) {
            System.out.println("ERROR: n and k must be integers.");
            System.exit(1);
        }
    
        int n = Integer.parseInt(args[0]);
        int k = Integer.parseInt(args[1]);

        if (k > n || k < 0) {
            System.out.printf("Invalid Input k cannot be greater than n.\n");
            System.exit(1);
        }

        long start, end;
        BigInteger result;

        // /***** testing Chooose function without memoization **** */
        // start = System.currentTimeMillis();
        // result = binomial(n, k);
        // end = System.currentTimeMillis();
        // System.out.printf("Result (regular): %s\nTime: %.2f\n", result.toString(),
        // (end-start)/1000.0);
        // /***** testing Chooose function without memoization **** */
        

        /***** testing Chooose function with memoization **** */
        start = System.currentTimeMillis();
        result = binomial(n, k);
        end = System.currentTimeMillis();
        System.out.printf("Result (regular): %s\nTime: %.2f\n", result.toString(), (end - start) / 1000.0);
        /***** testing Chooose function with memoization **** */

    }
    

    // public static BigInteger binomial(int n, int k) {
    //     // base
    //     if (k == 0 || n == k) {
    //         return BigInteger.ONE;
    //     }
    //     // recursive call
    //     return binomial(n - 1, k).add(binomial(n - 1, k - 1));
    // }

    public static BigInteger binomial(int n, int k) {
        // base
        if (k > n || k < 0) {
            throw new IllegalArgumentException("Invalid Input k cannot be greater than n.");
        }

        if (k == 0 || n == k) {
            return BigInteger.ONE;
        }
        Pair<Integer, Integer> pair = new Pair<Integer, Integer>(n, k);
        if (memoizationTable.containsKey(pair)) {
            return memoizationTable.get(pair);
        } else {
            // recursive call
            BigInteger result = binomial(n - 1, k).add(binomial(n - 1, k - 1));
            memoizationTable.put(pair, result);
            return result;
        }
    }
}
