class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int> &vis,vector<int> &pathvis,vector<int> &check){
        vis[i]=1;
        pathvis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(dfs(j,adj,vis,pathvis,check))return true;
            }
            else if(pathvis[j]){return true;}
        }
        check[i]=1;
        pathvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){ans.push_back(i);}
        }
        return ans;        
    }
};