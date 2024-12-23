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
        int cnt(vector<int> &v)
    {
        vector<int> sv(v.begin(),v.end());
        sort(sv.begin(),sv.end());
        unordered_map<int,int> mp;
        int ans = 0;
        int g = 0;
        for(auto i: v)
        {
            mp[i] = g++; 
        }
        
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i] == sv[i])
                continue;
            int c = mp[sv[i]];
            mp[v[i]] = c;
            mp[v[c]] = i;
            swap(v[c],v[i]);
            ans++;
        }
        
        return ans;
        
    }
    
    int bfs(TreeNode* r)
    {
        int res = 0;
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            while(sz--)
            {
                auto v = q.front();
                q.pop();
                temp.push_back(v->val);
                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
            }
            
            res += cnt(temp);
        }
        
        return res;
    }
    int minimumOperations(TreeNode* root) {
        return bfs(root);
    }
};