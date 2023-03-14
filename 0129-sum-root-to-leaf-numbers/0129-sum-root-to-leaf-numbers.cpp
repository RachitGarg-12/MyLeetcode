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
    int sum=0;
    void dfs(TreeNode* cur,int num){
        if(cur->left==NULL && cur->right==NULL){
            num*=10;
            num+=cur->val;
            sum+=num;
            return;
        }
        num*=10;
        num+=cur->val;
        if(cur->left!=NULL)dfs(cur->left,num);
        if(cur->right!=NULL)dfs(cur->right,num);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};