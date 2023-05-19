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
    void dfs(TreeNode* p,TreeNode* root,TreeNode* target,map<TreeNode*,TreeNode*>&par){
        par[root]=p;
        if(root==target){return;}
        if(root->left){dfs(root,root->left,target,par);}
        if(root->right){dfs(root,root->right,target,par);}
    }
    void dfs2(map<TreeNode*,TreeNode*>&par,TreeNode* last,TreeNode* cur,int height,int k,vector<int>&ans){
        queue<TreeNode*> q;
        q.push(cur);
        int lev=height;
        while(!q.empty() && lev<=k){
            int l=q.size();
            while(l--){
                TreeNode *t=q.front();q.pop();
                if(t==last){continue;}
                if(lev==k){ans.push_back(t->val);}
                if(t->left){q.push(t->left);}
                if(t->right){q.push(t->right);}
            }
            lev++;
        }
        if(height+1<=k && par[cur]!=NULL){dfs2(par,cur,par[cur],height+1,k,ans);}
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> par;
        dfs(NULL,root,target,par);
        vector<int> ans;
        if(par[target]!=NULL){
            dfs2(par,target,par[target],1,k,ans);
        }
        queue<TreeNode*> q;
        q.push(target);
        int lev=0;
        while(!q.empty() && lev<=k){
            int l=q.size();
            while(l--){
                TreeNode *t=q.front();q.pop();
                if(lev==k){ans.push_back(t->val);}
                if(t->left){q.push(t->left);}
                if(t->right){q.push(t->right);}
            }
            lev++;
        }
        return ans;
    }
};