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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){return {};}
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rev=false;
        while(!q.empty()){
            int l=q.size();
            vector<int> temp(l);
            for(int i=0;i<l;i++){
                TreeNode* cur=q.front();q.pop();
                if(rev==true){temp[l-1-i]=cur->val;}
                else{temp[i]=cur->val;}
                if(cur->left!=NULL){q.push(cur->left);}
                if(cur->right!=NULL){q.push(cur->right);}
            }
            ans.push_back(temp);
            rev=!rev;
        }
        return ans;
    }
};