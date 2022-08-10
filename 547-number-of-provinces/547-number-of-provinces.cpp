class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int> &vis){
        vis[node]=1;
        for(int j=1;j<=isConnected.size();j++){
            if(isConnected[node][j-1]==1 && vis[j-1]==0){ dfs(j-1,isConnected,vis);}
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();vector<int> vis(n,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i-1]){
                ans++;
                dfs(i-1,isConnected,vis);
            }
        }
        return ans;
    }
};