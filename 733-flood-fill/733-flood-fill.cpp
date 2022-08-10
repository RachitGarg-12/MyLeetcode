class Solution {
public:
    void bfs(int samecolor,int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,int n,int m,int color){
        vis[i][j]=1;grid[i][j]=color;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> p=q.front();q.pop();
            int r=p.first,c=p.second;
            if(r>0){
                if(grid[r-1][c]==samecolor && vis[r-1][c]==0){vis[r-1][c]=1;grid[r-1][c]=color;q.push({r-1,c});}
            }
            if(r<n-1){
                if(grid[r+1][c]==samecolor && vis[r+1][c]==0){vis[r+1][c]=1;grid[r+1][c]=color;q.push({r+1,c});}
            }
            if(c<m-1){
                if(grid[r][c+1]==samecolor && vis[r][c+1]==0){vis[r][c+1]=1;grid[r][c+1]=color;q.push({r,c+1});}
            }
             if(c>0){
                if(grid[r][c-1]==samecolor && vis[r][c-1]==0){vis[r][c-1]=1;grid[r][c-1]=color;q.push({r,c-1});}
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int samecolor=grid[sr][sc];
        bfs(samecolor,sr,sc,grid,vis,n,m,color);
        return grid;
        
    }
};