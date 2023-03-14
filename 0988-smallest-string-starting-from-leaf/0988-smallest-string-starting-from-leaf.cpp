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
    string ans="";
    void dfs(TreeNode* cur,string s){
        s+=('a'+cur->val);
        if(cur->left==NULL && cur->right==NULL){
            reverse(s.begin(),s.end());
            if(ans.size()==0){ans=s;}
            else{
                if(s < ans){ans=s;}
            }
            return;
        }
        if(cur->left!=NULL){dfs(cur->left,s);}
        if(cur->right!=NULL){dfs(cur->right,s);}
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};