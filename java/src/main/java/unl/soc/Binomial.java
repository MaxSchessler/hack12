package unl.soc;

import java.math.BigInteger;
import java.util.Map;
import java.util.HashMap;

public class Binomial {

    public static Map<Pair<Integer, Integer>, BigInteger> memoizationTable;

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage 'java Binomial.java <n> <k> ");
            System.exit(1);
        }

        int n = Integer.parseInt(args[0]);
        int k = Integer.parseInt(args[1]);

        if (n == 0 || k == 0) {
            System.out.printf("%s or %s not valid\n", args[0], args[1]);
            System.exit(1);
        }

        if (k > n) {
            System.out.printf("Invalid Input k cannot be greater than n.\n");
            System.exit(1);
        }

        long start, end;
        BigInteger result;

        // /***** testing Chooose function without memoization **** */
        // start = System.currentTimeMillis();
        // result = choose(n, k);
        // end = System.currentTimeMillis();
        // System.out.printf("Result (regular): %s\nTime: %.2f\n", result.toString(),
        // (end-start)/1000.0);
        // /***** testing Chooose function without memoization **** */

        // init the map and use it in the function
        memoizationTable = new HashMap<>();

        /***** testing Chooose function with memoization **** */
        start = System.currentTimeMillis();
        result = chooseWithMemoization(n, k);
        end = System.currentTimeMillis();
        System.out.printf("Result (regular): %s\nTime: %.2f\n", result.toString(), (end - start) / 1000.0);
        /***** testing Chooose function with memoization **** */

        System.out.printf("Number of objects: %d\n", memoizationTable.values().size());

    }

    public static BigInteger choose(int n, int k) {
        // base
        if (k == 0 || n == k) {
            return BigInteger.ONE;
        }
        // recursive call
        return choose(n - 1, k).add(choose(n - 1, k - 1));
    }

    public static BigInteger chooseWithMemoization(int n, int k) {
        // base
        if (k == 0 || n == k) {
            return BigInteger.ONE;
        }
        Pair<Integer, Integer> pair = new Pair<Integer, Integer>(n, k);
        if (memoizationTable.containsKey(pair)) {
            return memoizationTable.get(pair);
        } else {
            // recursive call
            BigInteger result = chooseWithMemoization(n - 1, k)
            .add(chooseWithMemoization(n - 1, k - 1));
            memoizationTable.put(pair, result);
            return result;
        }
    }
}
