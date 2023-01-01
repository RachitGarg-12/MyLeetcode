class Solution {
public:
     int n,m;
     void bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>& q,vector<vector<int>> &vis,vector<vector<int>> &dis){      
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front();
            q.pop();
            int r=p.first.first,c=p.first.second,t=p.second;
            vis[r][c]=1;
            dis[r][c]=t;
            cout<<r<<" "<<c<<" "<<t<<endl;
            if(r-1>=0 && grid[r-1][c]==1 && vis[r-1][c]==0){
                    q.push({{r-1,c},t+1});vis[r+-1][c]=1;
            dis[r-1][c]=t+1;
            }
            if(r<n-1 && grid[r+1][c]==1 && vis[r+1][c]==0){                                                   q.push({{r+1,c},t+1});vis[r+1][c]=1;
            dis[r+1][c]=t+1;
            }
            if(c<m-1 && grid[r][c+1]==1 && vis[r][c+1]==0){
                    q.push({{r,c+1},t+1});vis[r][c+1]=1;
            dis[r][c+1]=t+1;
            }
            if(c-1>=0 && grid[r][c-1]==1 && vis[r][c-1]==0){
                     q.push({{r,c-1},t+1});vis[r][c-1]=1;
            dis[r][c-1]=t+1;
            }
            
        }

    }

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;bool done=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
       bfs(grid,q,vis,dis);
       return dis;
    }
};