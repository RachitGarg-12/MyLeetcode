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
    vector<string> ans;
    void dfs(TreeNode* cur,string s){
        if(s.size()!=0){s+="->";}
        s+=to_string(cur->val);
        if(cur->left==NULL && cur->right==NULL){
            ans.push_back(s);return;
        }
        if(cur->left!=NULL){dfs(cur->left,s);}
        if(cur->right!=NULL){dfs(cur->right,s);}
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};