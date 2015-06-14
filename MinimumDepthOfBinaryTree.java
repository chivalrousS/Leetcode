package leetcode;
/*
 * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.
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
public class MinimumDepthOfBinaryTree {
	public int minDepth(TreeNode root) {
        if(root == null)
            return 0;
        ArrayList<TreeNode> array = new ArrayList<TreeNode>();
        array.add(root);
        int count = 1;
        while(! array.isEmpty())
        {
            ArrayList<TreeNode> tmp = new ArrayList<TreeNode>();
            for(TreeNode treeNode:array)
            {
                if(treeNode.left == null && treeNode.right == null)
                    return count;
                if(treeNode.left != null)
                    tmp.add(treeNode.left);
                if(treeNode.right != null)
                    tmp.add(treeNode.right);
            }
            ++count;
            array = new ArrayList<TreeNode>(tmp);
        }
        return count;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
