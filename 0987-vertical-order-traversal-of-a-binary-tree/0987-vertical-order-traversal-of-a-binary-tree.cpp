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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();q.pop();
            TreeNode *cur=p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(cur->val);
            if(cur->left){
                q.push({cur->left,{x-1,y+1}});
            }
            if(cur->right){
                q.push({cur->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                for(auto it:q.second){
                    col.push_back(it);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};