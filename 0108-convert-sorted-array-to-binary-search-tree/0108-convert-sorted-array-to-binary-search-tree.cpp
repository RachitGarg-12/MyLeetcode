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
    TreeNode* sortedArrayToBST(vector<int>& a) {
        int n=a.size();
        if(n==0){return NULL;}
        if(n==1){return new TreeNode(a[0]);}
        int m=n/2;
        TreeNode *temp= new TreeNode(a[m]);
        vector<int> l(a.begin(),a.begin()+m);
        vector<int> r(a.begin()+m+1,a.end());
        temp->left = sortedArrayToBST(l);
        temp->right = sortedArrayToBST(r);
        return temp;   
    }
};