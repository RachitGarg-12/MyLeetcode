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
    bool isValidBST(TreeNode* root) {
        return val(root,LONG_MAX,LONG_MIN);
    }
    bool val(TreeNode *root,long mx,long mn){
        if(root==NULL){return true;}
        if(root->val<=mn || root->val>=mx){return false;}
        return val(root->left,root->val,mn) && val(root->right,mx,root->val);
    }
};