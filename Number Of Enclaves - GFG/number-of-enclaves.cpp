//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int n,m;
   int dx[4]={-1,0,0,1};
   int dy[4]={0,-1,1,0};
   void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis){
       vis[i][j]=1;
       grid[i][j]=0;
       for(int k=0;k<4;k++){
           int x=i+dx[k];
           int y=j+dy[k];
           if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1){
               dfs(x,y,grid,vis);
           }
       }
       
   }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        n=grid.size();m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){ 
            if(!vis[i][0] && grid[i][0]==1){dfs(i,0,grid,vis);}
            if(!vis[i][m-1] && grid[i][m-1]==1){dfs(i,m-1,grid,vis);}
        }   
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){dfs(0,j,grid,vis);}
            if(!vis[n-1][j] && grid[n-1][j]==1){dfs(n-1,j,grid,vis);}
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1){ans++;}
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends