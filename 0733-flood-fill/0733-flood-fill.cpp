class Solution {
public:
    vector<vector<int>> vis;
    int n,m;
    void dfs(vector<vector<int>>& a, int i, int j, int color){
        vis[i][j]=1;
        
        if(i>0 && !vis[i-1][j] && a[i-1][j]==a[i][j]){dfs(a,i-1,j,color);}
        if(i<n-1 && !vis[i+1][j] && a[i+1][j]==a[i][j]){dfs(a,i+1,j,color);}
        if(j>0 && !vis[i][j-1] && a[i][j-1]==a[i][j]){dfs(a,i,j-1,color);}
        if(j<m-1 && !vis[i][j+1] && a[i][j+1]==a[i][j]){dfs(a,i,j+1,color);}
        
        a[i][j]=color;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        n=a.size(),m=a[0].size();
        vis.resize(n,vector<int>(m,0));
        dfs(a,sr,sc,color);
        return a;
    }
};