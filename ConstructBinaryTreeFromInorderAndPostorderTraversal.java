package leetcode;
/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
public class ConstructBinaryTreeFromInorderAndPostorderTraversal {
	public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || inorder.length == 0 || postorder == null || postorder.length == 0) {  
            return null;  
        }  
          
        if (inorder.length == 1) {  
            return new TreeNode(inorder[0]);  
        }  
          
        TreeNode node = new TreeNode(postorder[postorder.length - 1]);  
        int index = indexOf(inorder, node.val);  
        if (index >= 1) {  
            node.left = buildTree(Arrays.copyOfRange(inorder, 0, index), Arrays.copyOfRange(postorder, 0, index));  
        }  
        if (postorder.length -1 >=  index)  
            node.right = buildTree(Arrays.copyOfRange(inorder, index + 1, inorder.length), Arrays.copyOfRange(postorder, index, postorder.length - 1));  
        return node;      
    }  
      
    public int indexOf(int[] arr, int val) {  
        if (arr == null || arr.length == 0) return -1;  
        for (int i = 0; i < arr.length; i++) {  
            if (arr[i] == val) {  
                return i;  
            }  
        }  
        return -1;  
    }
}
