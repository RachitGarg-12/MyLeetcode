/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool evaluateTree(TreeNode* root) {
        //root is leaf
        if(root->val<2) return root->val;
        //root is or
        else if(root->val==2) return evaluateTree(root->left) || evaluateTree(root->right);
        //root is and
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};