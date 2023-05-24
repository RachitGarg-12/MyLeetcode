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
    vector<TreeNode*> buildtree(int start,int end){
        vector<TreeNode*> ans;
        if(start>end){return {NULL};}
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=buildtree(start,i-1);
            vector<TreeNode*> right=buildtree(i+1,end);
            
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode *root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return buildtree(1,n);
    }
};