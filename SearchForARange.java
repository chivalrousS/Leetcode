package leetcode;
import java.util.*;
/*
 * Given a sorted array of integers, find the starting and ending position 
 * of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */
public class SearchForARange {
	public static int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        int lens = nums.length;
        int start = 0;
        int end = lens - 1;
        int left = FindIndex(nums,0,lens-1,target);
        int right = left;
        if (left == -1)
        {
        	res[0] = -1;
        	res[1] = -1;
        	return res;
        }
        while((left > start) && (nums[left] == nums[left-1]))
        	left = FindIndex(nums,0,left-1,target);
        while((right < end) && (nums[right] == nums[right+1] ))
        	right = FindIndex(nums,right+1,end,target);
        res[0] = left;
        res[1] = right;
        return res; 
    }
	
	public static int FindIndex(int[] nums,int left,int right,int target)
	{
		int mid = 0;
		while(left <= right)
		{
			mid = left + (right - left)/2;
			if(nums[mid] < target)
			{
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
			if(nums[mid] == target)
		    	return mid;
		}
	    	return -1;
	}
	
	public static void main(String[] args)
	{
		int[] nums = {1, 7, 7, 8, 8, 10};
		int[] res = searchRange(nums,8);
		for(int r:res)
			System.out.println(r);
	}

}
