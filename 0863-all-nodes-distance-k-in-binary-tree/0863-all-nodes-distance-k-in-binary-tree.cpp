/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find_par(TreeNode* p,TreeNode* root,TreeNode* target,map<TreeNode*,TreeNode*>&par){
        par[root]=p;
        if(root==target){return;}
        if(root->left){find_par(root,root->left,target,par);}
        if(root->right){find_par(root,root->right,target,par);}
    }
    void bfs(map<TreeNode*,TreeNode*>&par,TreeNode* cur,int k,vector<int>&ans){
        queue<TreeNode*> q;
        q.push(cur);
        map<TreeNode*,int> vis;
        int lev=0;
        while(!q.empty() && lev<=k){
            int l=q.size();
            while(l--){
                TreeNode *t=q.front();q.pop();
                vis[t]=1;
                if(lev==k){ans.push_back(t->val);}
                if(t->left && !vis[t->left]){q.push(t->left);}
                if(t->right && !vis[t->right]){q.push(t->right);}
                if(par[t]!=NULL && !vis[par[t]]){q.push(par[t]);}
            }
            lev++;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> par;
        find_par(NULL,root,target,par);
        vector<int> ans;
        bfs(par,target,k,ans);
        return ans;
    }
};