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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return build(0,n-1,preorder);
    }
    TreeNode* build(int l,int r,vector<int> &preorder){
        if(r-l<0){return NULL;}
        TreeNode *root=new TreeNode(preorder[l]);
        int ind=r;
        for(int i=l+1;i<=r;i++){
            if(preorder[i]>root->val){ind=i-1;break;}
        }
        root->left=build(l+1,ind,preorder);
        root->right=build(ind+1,r,preorder);
        return root;
    }
};