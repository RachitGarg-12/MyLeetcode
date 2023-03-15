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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool b=false;
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(b){
                if(cur->left!=NULL || cur->right!=NULL){return false;}
            }
            else{
                if(cur->left==NULL){b=true;}
                if(b && cur->right){return false;}
                if(cur->right==NULL){b=true;}
            }
            if(cur->left!=NULL){q.push(cur->left);}
            if(cur->right!=NULL){q.push(cur->right);}
        }
        return true;
    }
};