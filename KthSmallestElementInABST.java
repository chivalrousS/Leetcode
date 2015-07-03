package leetcode;
/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest
 *  element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the
 kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
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
public class KthSmallestElementInABST {
	 int index;
	    int value;
	    int m;
	    void dfs(TreeNode root)
	    {
	        if(root == null)
	            return;
	        dfs(root.left);
	        ++index;
	        if(m == index)
	        {
	            value = root.val;
	            return;
	        }
	        dfs(root.right);
	    }
	    public int kthSmallest(TreeNode root, int k) {
	        m =k ;
	        index = 0;
	        dfs(root);
	        return value;
	    }
}
