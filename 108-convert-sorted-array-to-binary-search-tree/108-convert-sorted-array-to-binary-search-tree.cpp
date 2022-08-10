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
    TreeNode *sortedArrayToBST(vector<int> &a) {
        if(a.size()==0) return NULL;
        if(a.size() == 1)  return new TreeNode(a[0]);
        int m = a.size()/2;TreeNode* root = new TreeNode(a[m]);
        vector<int> leftInts(a.begin(), a.begin()+m);
        vector<int> rightInts(a.begin()+m+1, a.end());
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);
        
        return root;
    }
};