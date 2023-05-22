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
        return build(preorder);
    }
    TreeNode* build(vector<int> preorder){
        if(preorder.size()==0){return NULL;}
        TreeNode *root=new TreeNode(preorder[0]);
        int l=preorder.size();
        vector<int> left,right;
        for(int i=1;i<l;i++){
            if(preorder[i]<root->val){left.push_back(preorder[i]);}
            else{right.push_back(preorder[i]);}
        }
        root->left=build(left);
        root->right=build(right);
        return root;
    }
};