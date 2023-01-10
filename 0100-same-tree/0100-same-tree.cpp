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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL)return false;
        if(q==NULL)return false;
        queue<TreeNode*> a,b;
        a.push(p);b.push(q);
        while(!a.empty() || !b.empty()){
            TreeNode *t1=a.front(),*t2=b.front();
            a.pop();b.pop();
            if(t1->val!=t2->val)return false;
            if(t1->right==NULL && t2->right!=NULL)return false;
            if(t1->right!= NULL){
                if(t2->right==NULL)return false;
                if(t1->right->val!=t2->right->val)return false;
                a.push(t1->right);b.push(t2->right);
            }
            if(t1->left==NULL && t2->left!=NULL)return false;
            if(t1->left!= NULL){
                if(t2->left==NULL)return false;
                if(t1->left->val!=t2->left->val)return false;
                a.push(t1->left);b.push(t2->left);
            }
        }
        if(a.size()!=b.size())return false;
        return true;
    }
};