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
    int findAllPaths(TreeNode*root,vector<int>&helper){
        if(root==NULL){
            return 0;
        }
        helper[root->val]+=1;
        if(!root->left&&!root->right){
            int odds=0;
            for(auto x:helper){
                if(x%2!=0) odds++;
            }
            //cout<<odds<<" "<<root->val<<endl;
            if(odds<=1){
                helper[root->val]-=1;
                return 1;
            }
        }
        int left=findAllPaths(root->left,helper);
        int right=findAllPaths(root->right,helper);
        helper[root->val]-=1;
        return left+right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> helper(10,0);
        return findAllPaths(root,helper);
    }
};