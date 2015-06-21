package leetcode;
import java.util.*;
/*
 * Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
public class Subsets {
	 public List<List<Integer>> subsets(int[] nums) {
	      List<List<Integer>> result = new ArrayList<List<Integer>>();

	      if(nums.length == 0){
	         return result;
	      } 

	      Arrays.sort(nums);
	      dfs(nums, 0, new ArrayList<Integer>(), result);
	      return result;
	     }

	    public void dfs(int[] s, int index, List<Integer> path, List<List<Integer>> result){
	    result.add(new ArrayList<Integer>(path));
	    for(int i = index; i < s.length; i++){
	        path.add(s[i]);
	        dfs(s, i+1, path, result);
	        path.remove(path.size()-1);
	    }
	}
}
