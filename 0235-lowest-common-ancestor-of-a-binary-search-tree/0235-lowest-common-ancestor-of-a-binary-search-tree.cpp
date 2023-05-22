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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mx=max(q->val,p->val),mn=min(q->val,p->val);
        if(root==NULL || (root->val>=mn && root->val<=mx)){return root;}
        if(root->val>mx){
            return lowestCommonAncestor(root->left,p,q);
        }
        return lowestCommonAncestor(root->right,p,q);
    }
};