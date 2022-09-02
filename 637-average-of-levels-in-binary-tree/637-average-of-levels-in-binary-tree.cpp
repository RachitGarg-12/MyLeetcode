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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();q.pop();
                if(temp->left!=NULL){q.push(temp->left);}
                if(temp->right!=NULL){q.push(temp->right);}
                sum += temp->val;
            }
            ans.push_back(double(sum)/n);
        }
        return ans;
    }
};