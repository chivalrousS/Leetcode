package leetcode;
import java.util.*;
/*
 * Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */
public class HappyNumber {
	
	public static int SquaresOfdigits(int n)
	{
		int result = 0,temp = 0;
		while(n > 0)
		{
			temp = n % 10;
			n = n / 10;
			result += Math.pow(temp, 2);
		}
		return result;
	}
	
    public static boolean isHappy(int n) {
    	HashSet<Integer> set = new HashSet<Integer>();
    	int result = n;
    	while( result != 1)
    	{
    		if(!set.contains(result))
    			set.add(result);
    		else 
    			return false;
    		result = SquaresOfdigits(result);
    	}	
        return true;
    }
    
    public static void main(String[] args)
    {
    	System.out.println(isHappy(19));
    }

}
