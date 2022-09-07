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
    string preorder(TreeNode* temp){
        if(temp==NULL){return "";}
        string ans="";
        ans+=to_string(temp->val);
        if(temp->left!=NULL){ans+='('+preorder(temp->left)+')';}
        else if(temp->right!=NULL){ans+="()";}
        if(temp->right!=NULL){ans+='('+preorder(temp->right)+')';}  
        return ans;
    }
    string tree2str(TreeNode* root) {
        TreeNode* temp=root;
        string ans=preorder(temp);
        return ans;
    }
};