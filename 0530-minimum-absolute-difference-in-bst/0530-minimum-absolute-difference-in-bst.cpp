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
    int ans=1e9;
    int prev=-1;
    void f(TreeNode* root){
        if(root){
            f(root->left);
            if(prev==-1){prev=root->val;}
            else{
                ans=min(ans,abs(root->val-prev));
                prev=root->val;
            }
            f(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        f(root);
        return ans;
    }
};