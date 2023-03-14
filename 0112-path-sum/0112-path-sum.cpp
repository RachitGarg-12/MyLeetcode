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
    bool pos=false;
    int t;
    void dfs(TreeNode* cur,int sum){
        if(cur->left==NULL && cur->right==NULL){
            if(sum+cur->val==t){pos=true;}
            return;
        }
        sum+=cur->val;
        if(cur->left){dfs(cur->left,sum);}
        if(cur->right){dfs(cur->right,sum);}
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){return false;}
        t=targetSum;
        dfs(root,0);
        return pos;
    }
};