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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (root->right==NULL && root->left==NULL)){return root;}
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *t=q.front();
            q.pop();
            swap(t->left,t->right);
            if(t->left!=NULL){q.push(t->left);}
            if(t->right!=NULL){q.push(t->right);}
        }
        return root;
    }
};