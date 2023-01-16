class Solution {
public:
    long long ans=0;
    vector<int> value;
    void dfs(int i,vector<vector<int>> &adj,vector<bool> &vis){
        vis[i]=true;
        for(auto j:adj[i]){
            if(!vis[j]){
               dfs(j,adj,vis);
            }
            ans+=(long long)value[i]+value[j];
        }
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<pair<int,int>> sz;
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            sz.push_back({adj[i].size(),i});
        }
        sort(sz.begin(),sz.end());
        int val=n;
        value.resize(n);
        int m=sz.size();
        for(int i=m-1;i>=0;i--){
            value[sz[i].second]=val;val--;
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
       return ans/2; 
    }
};