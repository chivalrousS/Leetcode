package leetcode;
/*
 * You are a professional robber planning to rob houses along a street.
 *  Each house has a certain amount of money stashed, the only constraint
 *   stopping you from robbing each of them is that adjacent houses have 
 *   security system connected and it will automatically contact the police
 *    if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of 
each house, determine the maximum amount of money you can rob tonight without
 alerting the police.
 */
public class HouseRobber {
	public static int rob(int[] nums) {
        int len = nums.length;
        int[] s = nums.clone();
        if(len > 2)
           s[2] += s[0];
        for(int i=3;i < len;)
        {
            s[i] += Math.max(s[i-2],s[i-3]);
            ++i;
        }
        if(len <= 0)
           return 0;
        else if (len == 1)
           return s[0];
        else
           return Math.max(s[len-1],s[len-2]);
    }

	public static void main(String[] args) {
		int[] nums = {1,3,5,7};
		System.out.println(rob(nums));
	}

}
