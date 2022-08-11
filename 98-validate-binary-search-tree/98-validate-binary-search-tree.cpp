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
       if(root==NULL) return true;
        return validate(root, LONG_MAX, LONG_MIN);
    }
    bool validate(TreeNode* node,long long mx,long long mn) {
        if (node == NULL) return true;
        if(node->val>=mx || node->val<=mn) return false;
        return validate(node->left,node->val,mn) && validate(node->right,mx,node->val);
    }
};