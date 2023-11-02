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
    int ans=0;
    pair<int,int> dfs(TreeNode *cur){
        if(cur==NULL){return {0,0};}
        auto l= dfs(cur->left);
        auto r= dfs(cur->right);
        int sum= l.first+r.first+ cur->val;
        int num= l.second + r.second + 1;
        if((sum/num) == cur->val){
            ans++;
        }
        return {sum,num};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};