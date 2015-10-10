package leetcode;
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

public class BestTimeToBuyAndSellStockIII {
	public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int tmp1 = 0, tmp2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            tmp2 = Math.max(tmp2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    tmp1-i);  // The maximum if we've just buy  2nd stock so far.
            tmp1 = Math.max(tmp1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return tmp2; ///Since tmp1 is initiated as 0, so tmp2 will always higher than tmp1.
    }
}
