package leetcode;
/*
 * Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
 */

public class FactorialTrailingZeroes {
	public static int trailingZeroes(int n) {
        if(n<5) return 0;

        int count=0;
        int test=1;
        while(n>test) {
			count += n/5;
			n /= 5;
        }
		return count;
    }
	public static void main(String[] args) {
		int n = 5;
		System.out.println(trailingZeroes(n));
	}
}
