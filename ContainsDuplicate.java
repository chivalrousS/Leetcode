package leetcode;

import java.util.HashSet;
/*
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 */
public class ContainsDuplicate {

public boolean containsDuplicate(int[] nums) {
        int lens = nums.length;
        if(lens <= 1)
        	return false;
        HashSet<Integer> set = new HashSet<>();
        for(int num:nums)
        {
        	if (set.contains(num))
        	    return true;
        	else {
				set.add(num);
			}
        }
        return false;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	}

}
