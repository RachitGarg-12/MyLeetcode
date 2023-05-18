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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int l=q.size();
            int mm=q.front().second;
            int mn=1e9,mx=0,in=1;
            for(int i=0;i<l;i++){
                auto [cur,ind]=q.front();q.pop();
                ind-=mm;
                if(i==0){mn=ind;}
                if(i==l-1){mx=ind;}
                if(cur->left){q.push({cur->left,(long long)2*ind+1});}
                if(cur->right){q.push({cur->right,(long long)2*ind+2});}
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};