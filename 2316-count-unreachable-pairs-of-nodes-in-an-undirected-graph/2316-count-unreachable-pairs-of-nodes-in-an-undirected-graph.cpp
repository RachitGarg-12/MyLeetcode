class Solution {
public:

    void dfs(int i,vector<vector<int>> &adj,long long &len,vector<int> &vis){
        vis[i]=1;
        len++;
        for(auto& j:adj[i]){
            if(!vis[j]){dfs(j,adj,len,vis);}
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        long long t=(long long)n;
        long long ans= (t*(t-1))/2;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long len=0;
                dfs(i,adj,len,vis);
                ans -=(long long)(len*(len-1))/2;
            }
        }
        return ans;
    }
};