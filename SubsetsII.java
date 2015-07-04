package leetcode;
import java.util.*;
/*
 * Given a collection of integers that might contain duplicates, nums, 
 * return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

public class SubsetsII {
	public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer> array = new ArrayList<Integer>();
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.add(array);  
        if(nums==null) {  
            return result;  
        }  
        Arrays.sort(nums);  
        for(int i=1;i<=nums.length;i++) {  
            array.clear();  
            dfs(nums,0,i,array,result);  
        }  
        return result;  
    }
    
     void dfs(int[] number_array, int start, int number, List<Integer> array, List<List<Integer>> result) {  
        if(array.size()==number) {  
            result.add(new ArrayList<Integer>(array));  
            return;  
        }  
        int i = start;  
        while(i<number_array.length) {  
            array.add(number_array[i]);  
            dfs(number_array,i+1,number,array,result);  
            array.remove(array.size()-1);  
            while(i<(number_array.length-1)&&number_array[i]==number_array[i+1]) {  
                i++;  
            }  
            i++;  
        }  
    } 

}
