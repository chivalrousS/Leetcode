/**
 * Created by junbao on 2017/6/30.
 */

/**
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

 You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

 Example 1:
 Input:
 Tree 1                     Tree 2
 1                         2
 / \                       / \
 3   2                     1   3
 /                           \   \
 5                             4   7
 Output:
 Merged tree:
 3
 / \
 4   5
 / \   \
 5   4   7
 Note: The merging process must start from the root nodes of both trees.
 */


import javax.swing.tree.TreeNode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class MergeTwoBinaryTrees {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(null == t1 && null == t2)
            return null;
        int value = (null == t1 ? 0: t1.val) + (null == t2 ? 0: t2.val);
        TreeNode newNode = new TreeNode(value);
        newNode.left = mergeTrees(null == t1?null:t1.left, null==t2 ?t2:t2.left);
        newNode.right = mergeTrees(null==t1?null:t1.right,null==t2?null:t2.right);

        return newNode;
    }
}
