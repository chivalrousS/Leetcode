/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool PathSum(TreeNode *root,int sum,int val)
    {
         if(root==NULL)  return false;
         val+=root->val;
         if(root->left==NULL && root->right==NULL)
         {
             if(sum==val) return true;
             return false;
         }
         return PathSum(root->left,sum,val) || PathSum(root->right,sum,val);

    }
    bool hasPathSum(TreeNode* root, int sum) {
        return PathSum(root,sum,0);
    }
};
