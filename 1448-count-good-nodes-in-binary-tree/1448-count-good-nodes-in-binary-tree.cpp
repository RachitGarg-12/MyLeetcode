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
   map<TreeNode*,bool> m;
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        q.push({NULL,-1});
        int res = 1;
        
        // BFS
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int mx = curr.second;
            
            if(node){
                if(node->left){
                    if(mx<=node->left->val){
                        res++;
                    }
                    q.push({node->left,max(mx,node->left->val)});
                }
                if(node->right){
                    if(mx<=node->right->val){
                        res++;
                    }
                    q.push({node->right,max(mx,node->right->val)});
                }
            }
            else if(!q.empty()){
                q.push({NULL,-1});
            }
        }
        
        return res;
    }
};