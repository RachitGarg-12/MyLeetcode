class Solution {
public:
    void dfs(int samecolor,int r,int c,vector<vector<int>>& grid,vector<vector<int>> &vis,int n,int m,int color){
        vis[r][c]=1;grid[r][c]=color;
            if(r>0){
                if(grid[r-1][c]==samecolor && vis[r-1][c]==0){dfs(samecolor,r-1,c,grid,vis,n,m,color);}
            }
            if(r<n-1){
                if(grid[r+1][c]==samecolor && vis[r+1][c]==0){dfs(samecolor,r+1,c,grid,vis,n,m,color);}
            }
            if(c<m-1){
                if(grid[r][c+1]==samecolor && vis[r][c+1]==0){dfs(samecolor,r,c+1,grid,vis,n,m,color);}
            }
             if(c>0){
                if(grid[r][c-1]==samecolor && vis[r][c-1]==0){dfs(samecolor,r,c-1,grid,vis,n,m,color);}
            }
}
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int samecolor=grid[sr][sc];
        dfs(samecolor,sr,sc,grid,vis,n,m,color);
        return grid;
        
    }
};