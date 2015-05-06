/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        list<TreeNode*> node_list;
        if(root == NULL) return ans;
        node_list.push_front(root);
        TreeNode *head = root;
        while(!node_list.empty())
        {
            TreeNode *cur = node_list.front();

            if(cur -> right == head || cur -> left == head || ((cur -> right == NULL) && (cur -> left == NULL)))
            {
                node_list.pop_front();
                ans.push_back(cur -> val);
                head = cur;
            }
            else
            {
                if(cur -> right != NULL) node_list.push_front(cur -> right);
                if(cur -> left != NULL) node_list.push_front(cur -> left);
            }
        }

    }
};
