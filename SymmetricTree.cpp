/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *left,TreeNode *right)
    {
        if(!left && !right) return true;
        if((left && !right) || (!left && right) || (left->val!=right->val)) return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (!root->left && !root->right)) return true;
        return dfs(root->left,root->right);
    }
};
