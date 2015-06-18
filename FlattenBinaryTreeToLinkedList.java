package leetcode;
/*
 * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to 
the next node of a pre-order traversal.
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
public class FlattenBinaryTreeToLinkedList {
	public void flatten(TreeNode root) {
        while(root != null)
        {
        	if(root.left != null)
            {
               TreeNode pre = root.left;
               while(pre.right != null)
                  pre = pre.right; //找到左子树最右的节点
               pre.right = root.right;
               root.right = root.left;
               root.left = null;
            }
            root = root.right;
        }
   }
}
