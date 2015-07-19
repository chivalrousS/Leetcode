package leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import javax.swing.tree.TreeNode;

/*
 * Given a binary tree, imagine yourself standing on the right side of it,
 *  return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
public class BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
List<Integer> ans = new ArrayList<Integer>();
        
        if(root == null)
        	return ans;
        
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        queue.add(null);
        
        while(!queue.isEmpty())
        {
        	TreeNode node = queue.pollFirst();
        	
        	if(node == null)
        	{
        		if(queue.isEmpty())
        			break;
        		else {
					queue.add(null);
        		}
        	}
        	else {
				if(queue.peek() == null)
					ans.add(node.val);
				if(node.left != null)
					queue.add(node.left);
				if(node.right != null)
					queue.add(node.right);
			}
        }
        return ans;
    }
}
