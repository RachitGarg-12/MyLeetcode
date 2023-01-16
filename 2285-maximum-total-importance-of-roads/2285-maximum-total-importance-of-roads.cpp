class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       vector<vector<int>>adj(n);
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({adj[i].size(),i});
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        for(int i=0;i<temp.size();i++)
        {
            mp[temp[i].second]=i+1;
        }
        long long int ans=0;
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            ans=ans+mp[u]+mp[v];
        }
        return ans;
    }
};