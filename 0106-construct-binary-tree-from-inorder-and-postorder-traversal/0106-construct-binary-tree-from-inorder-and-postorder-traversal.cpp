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


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n=inorder.size();
        map<int,int> ind;
        for(int i=0;i<n;i++){
            ind[inorder[i]]=i;
        }
        TreeNode *root= build(postorder,0,n-1,inorder,0,n-1,ind);
        return root;
        
    }
    TreeNode *build(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,map<int,int>&ind){
        if(poststart > postend || instart > inend){return NULL;}
        TreeNode *root=new TreeNode(postorder[postend]);
        int inroot=ind[root->val];
        int numsleft=inroot-instart-1;
        root->left = build(postorder,poststart,poststart+numsleft,inorder,instart,inroot-1,ind);
        root->right = build(postorder,poststart+numsleft+1,postend-1,inorder,inroot+1,inend,ind);
        
        return root;
    }
};