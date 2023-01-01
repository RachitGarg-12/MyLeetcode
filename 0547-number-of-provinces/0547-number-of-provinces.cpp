class Solution {
public:
    int n;
    void dfs(int i,vector<int>&vis,vector<vector<int>>& isConnected){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(i==j){continue;}
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(j,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
          n=isConnected.size();
          vector<int> vis(n,0);
         int provinces=0;
          for(int i=0;i<n;i++){
              if(!vis[i]){
                  provinces++;dfs(i,vis,isConnected);
              }
          }
        return provinces;
    }
};