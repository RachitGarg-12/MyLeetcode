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
    void dfs(TreeNode* root,int lev,vector<int>&ans){
        if(lev==ans.size()){ans.push_back(root->val);}
        if(root->right){dfs(root->right,lev+1,ans);}
        if(root->left){dfs(root->left,lev+1,ans);}
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){return {};}
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
};