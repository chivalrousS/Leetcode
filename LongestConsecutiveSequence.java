package leetcode;
/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */
import java.util.*;

public class LongestConsecutiveSequence {
    public static int longestConsecutive(int[] nums) {
        if (nums.length == 0)
        	return 0;
        
        HashSet<Integer> set = new HashSet<Integer>();
        int max = 1;
        
        for(int e:nums)
        	set.add(e);
        
        for(int e:nums)
        {
        	int left = e - 1;
        	int right = e + 1;
        	int count = 1;
        	
        	while(set.contains(left))
        	{
        		++count;
        		set.remove(left);
        		--left;
        	}
        	while(set.contains(right))
        	{
        		++count;
        		set.remove(right);
        	    ++right;
        	}
        	
        	max = Math.max(count, max);
        }
        return max;
    }
    
    public static void main(String[] args)
    {
    	int[] nums = {100,4,200,1,3,2};
    	int max = longestConsecutive(nums);
    	System.out.println("max = "+max);
    }
    
}
