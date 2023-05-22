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
    void inorder(TreeNode *root,int &cnt,int &ans,int k){
        if(root->left){inorder(root->left,cnt,ans,k);}
        cnt++;
        if(cnt==k){ans=root->val;return;}
        if(root->right){inorder(root->right,cnt,ans,k);}
    }
    int kthSmallest(TreeNode *root, int K) {
        int cnt=0,ans=-1;
        inorder(root,cnt,ans,K);
        return ans;
    }
};