/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
      if(root == NULL)
        return 0;
      int left = TreeDepth(root->left);
      int right = TreeDepth(root->right);
     return (left>right)?(left+1):(right+1);
   }

    bool isBalanced(TreeNode *root) {
   if(root == NULL)
    return true;

  int Pleft = TreeDepth(root->left);
  int Pright = TreeDepth(root->right);
  int sum = Pleft - Pright;
  if(sum > 1 || sum < -1) 
    return false;
  return isBalanced(root->left)&&isBalanced(root->right);
    }
};