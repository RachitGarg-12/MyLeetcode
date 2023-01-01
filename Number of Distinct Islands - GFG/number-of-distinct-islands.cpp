//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n,m;
    void dfs(int r,int c,int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>> &v){
        vis[i][j]=1;
        v.push_back({r-i,c-j});
        if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]==0){dfs(r,c,i-1,j,grid,vis,v);}
        if(i+1<n && grid[i+1][j]==1 && vis[i+1][j]==0){dfs(r,c,i+1,j,grid,vis,v);}
        if(j-1>=0 && grid[i][j-1]==1 && vis[i][j-1]==0){dfs(r,c,i,j-1,grid,vis,v);}
        if(j+1<m && grid[i][j+1]==1 && vis[i][j+1]==0){dfs(r,c,i,j+1,grid,vis,v);}
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> v;
                    dfs(i,j,i,j,grid,vis,v);
                    s.insert(v);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends