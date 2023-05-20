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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> ind;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            ind[inorder[i]]=i;
        }
        TreeNode *root=build(preorder,0,n-1,inorder,0,n-1,ind);
        return root;
    }
    TreeNode *build(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>&ind){
        if(prestart > preend || instart > inend){return NULL;}
        TreeNode *root=new TreeNode(preorder[prestart]);
        int inroot=ind[root->val];
        int numsleft=inroot-instart;
        root->left = build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,ind);
        root->right = build(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,ind);
        
        return root;
    }
};