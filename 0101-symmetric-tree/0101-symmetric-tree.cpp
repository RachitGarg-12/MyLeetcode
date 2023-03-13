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
    bool mirror(TreeNode* leftnode,TreeNode* rightnode){
        if(leftnode==NULL && rightnode==NULL){return true;}
        if(leftnode==NULL || rightnode==NULL || leftnode->val!=rightnode->val){return false;}
        return mirror(leftnode->left,rightnode->right) && mirror(leftnode->right,rightnode->left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left,root->right);
    }
};