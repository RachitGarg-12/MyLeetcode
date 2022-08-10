class Solution {
public:
    
     int bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>& q,vector<vector<int>> &vis,int n,int m){
        int ans=0;
        
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front();q.pop();
            int r=p.first.first,c=p.first.second,t=p.second;
            ans=max(ans,t);
            // cout<<r<<" "<<c<<" "<<grid[r][c]<<" "<<ans<<endl;
            if(r>0){
                if(grid[r-1][c]==1 && vis[r-1][c]==0){
                    vis[r-1][c]=1;q.push({{r-1,c},t+1});grid[r-1][c]=2;}
            }
            if(r<n-1){
                if(grid[r+1][c]==1 && vis[r+1][c]==0){vis[r+1][c]=1;q.push({{r+1,c},t+1});grid[r+1][c]=2;}
            }
            if(c<m-1){
                if(grid[r][c+1]==1 && vis[r][c+1]==0){vis[r][c+1]=1;q.push({{r,c+1},t+1});grid[r][c+1]=2;}
            }
             if(c>0){
                if(grid[r][c-1]==1 && vis[r][c-1]==0){vis[r][c-1]=1;q.push({{r,c-1},t+1});grid[r][c-1]=2;}
            }
            
        }
         return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;bool done=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && vis[i][j]==0){
                    done=true;q.push({{i,j},0});
                }
            }
        }
        int ans=bfs(grid,q,vis,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }}
      
        return done?ans:0;
    }
};