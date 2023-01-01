class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>> &vis){
        vis[i][j]=1;
        if(i-1>=0 && grid[i-1][j]=='1' && vis[i-1][j]==0){dfs(i-1,j,grid,vis);}
        if(i+1<n && grid[i+1][j]=='1' && vis[i+1][j]==0){dfs(i+1,j,grid,vis);}
        if(j-1>=0 && grid[i][j-1]=='1' && vis[i][j-1]==0){dfs(i,j-1,grid,vis);}
        if(j+1<m && grid[i][j+1]=='1' && vis[i][j+1]==0){dfs(i,j+1,grid,vis);}
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return islands;
    }
};