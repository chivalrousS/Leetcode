package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * Given a set of candidate numbers (C) and a target number (T), find 
 * all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
 */
public class CombinationSum {
	List<List<Integer>> result;  
    List<Integer> solu;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        result = new ArrayList<>();  
        solu = new ArrayList<>();  
        Arrays.sort(candidates);  
        getCombination(candidates, target, 0, 0);  
        return result; 
    }
    public void getCombination(int[] candidates, int target, int sum, int level){  
        if(sum>target) return;  
        if(sum==target){  
            result.add(new ArrayList<>(solu));  
            return;  
        }  
        for(int i=level;i<candidates.length;i++){  
            sum+=candidates[i];  
            solu.add(candidates[i]);  
            getCombination(candidates, target, sum, i);  
            solu.remove(solu.size()-1);  
            sum-=candidates[i];  
        }  
    }  

}
