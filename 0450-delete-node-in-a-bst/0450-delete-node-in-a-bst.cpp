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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){return root;}
        if(root->val==key){
            return helper(root);
        }
        TreeNode *cur=root;
        while(root){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{root=root->left;}
            }
            else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{root=root->right;}
            }
        }
        return cur;
    }
    
    TreeNode* helper(TreeNode *root){
        if(root->right==NULL){return root->left;}
        else if(root->left==NULL){return root->right;}
        TreeNode *largest=root->left;
        while(largest->right){largest=largest->right;}
        largest->right=root->right;
        
        return root->left;
    }
};