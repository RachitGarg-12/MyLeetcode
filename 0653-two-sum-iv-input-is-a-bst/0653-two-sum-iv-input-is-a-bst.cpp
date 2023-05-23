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
class BSTIterator {
public:
    stack<TreeNode*> s;
    bool rev=true;
    BSTIterator(TreeNode* root,bool isreverse) {
        rev=isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode *tmp=s.top();
        s.pop();
        if(rev){pushall(tmp->left);}
        else{pushall(tmp->right);}
        return tmp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    void pushall(TreeNode* node){
        while(node){
            s.push(node);
            if(rev){node=node->right;}
            else{node=node->left;}
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){return false;}
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k){return true;}
            else if(i+j>k){j=r.next();}
            else{i=l.next();}
        }
        return false;
        
    }
};