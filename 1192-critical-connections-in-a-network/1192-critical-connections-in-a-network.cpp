class Solution {
public:
    int timer=1;
    vector<vector<int>> bridges;
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis,int tin[],int low[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent){continue;}
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low);
                low[node]=min(low[node],low[it]);
                //node---it
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int tin[n];
        int low[n];
        vector<int> vis(n,0);
        dfs(0,-1,adj,vis,tin,low);
        return bridges;
    }
};