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
    int ans=INT_MAX;
    void dfs(int depth,TreeNode* root){
        if(root->right==NULL && root->left==NULL){ans=min(ans,depth);}
        if(root->left){dfs(depth+1,root->left);}
        if(root->right){dfs(depth+1,root->right);}
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){return 0;}
        dfs(1,root);
        return ans;
    }
};