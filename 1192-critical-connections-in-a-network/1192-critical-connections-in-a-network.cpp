class Solution {
public:
    int timer=1;
    vector<vector<int>> bridges;
    void dfs(int node,int parent,vector<vector<int>> &adj,int tin[],int low[]){
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent){continue;}
            if(tin[it]==-1){
                dfs(it,node,adj,tin,low);
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
        memset(tin,-1,sizeof(tin));
        int low[n];
        dfs(0,-1,adj,tin,low);
        return bridges;
    }
};