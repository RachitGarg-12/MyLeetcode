class Solution {
public:
    long long ans=0;
    void dfs(int i,vector<vector<int>> &adj,vector<int> &value,vector<int> &vis){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
               dfs(j,adj,value,vis);
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
        vector<int> value(n);
        int m=sz.size();
        for(int i=m-1;i>=0;i--){
            value[sz[i].second]=val;val--;
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,value,vis);
            }
        }
       return ans/2; 
    }
};