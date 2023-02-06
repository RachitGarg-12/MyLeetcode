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
    int f(TreeNode* cur,int mx){
        int ans=0;
        if(cur->val>=mx){ans++;mx=cur->val;}
        if(cur->left!=NULL){ans+=f(cur->left,mx);}
        if(cur->right!=NULL){ans+=f(cur->right,mx);}
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return f(root,root->val);
    }
};