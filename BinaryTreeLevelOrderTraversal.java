package leetcode;

import java.awt.geom.QuadCurve2D;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javax.swing.tree.TreeNode;

/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
    	List<List<Integer>> ans= new ArrayList<List<Integer>>();
    	TreeNode nextLevelStarter;
    	
    	Queue<TreeNode> q = new LinkedList<TreeNode>();
    	q.add(root);
    	
    	if(root != null)
    	{
    		if(root.left != null)
    			nextLevelStarter = root.left;
    		else if(root.right != null)
    			nextLevelStarter = root.right;
    		
    		else {
    			List<Integer> tmp = new ArrayList<Integer>();
    			tmp.add(root.val);
    			ans.add(tmp);
    			return ans;
			}
    	}
    	else
    		return ans;
    	
    	while(!q.isEmpty())
    	{
    		TreeNode currentNode = q.peek();
    		List<Integer> thisLevelList = new ArrayList<Integer>();
    		nextLevelStarter = null;
    		
    		while(q.peek() != nextLevelStarter && q.isEmpty() == false)
    		{
    			currentNode = q.remove();
    			//若nextLevelStarter 值为空，说明未找到下一层的起始节点
    			
    			if(nextLevelStarter == null)
    			{
    				if(currentNode.left != null)
    					nextLevelStarter = currentNode.left;
    				else {
    					if(currentNode.right != null)
    					{
    						nextLevelStarter = currentNode.right;
    					}
					}
    			}
    			
    			thisLevelList.add(currentNode.val);
    			if(currentNode.left != null)
    				q.add(currentNode.left);
    			if(currentNode.right != null)
    				q.add(currentNode.right);
    		}
    		ans.add(thisLevelList);
    	}
        return ans;
    }
}

public class BinaryTreeLevelOrderTraversal {
	
}