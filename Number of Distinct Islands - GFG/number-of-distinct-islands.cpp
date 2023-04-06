//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int n,m;
    bool valid(int i,int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void dfs(int r,int c,int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>> &v){
        vis[i][j]=1;
        v.push_back({r-i,c-j});
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(valid(nr,nc)){
                if(!vis[nr][nc] && grid[nr][nc]==1){dfs(r,c,nr,nc,grid,vis,v);}
            }
        }
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