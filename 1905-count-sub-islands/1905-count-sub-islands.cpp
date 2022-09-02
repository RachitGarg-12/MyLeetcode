class Solution {
public:
    int n,m;vector<vector<int>> vis;bool t=true;
    void dfs(vector<vector<int>>& a, vector<vector<int>>& b,int i,int j){
        vis[i][j]=1;
        // cout<<i<<" "<<j<<endl;
        if(a[i][j]==0){t=false;}
        if(i>0 && !vis[i-1][j] && b[i-1][j]==1){dfs(a,b,i-1,j);}
        if(i<n-1 && !vis[i+1][j] && b[i+1][j]==1){dfs(a,b,i+1,j);}
        if(j<m-1 && !vis[i][j+1] && b[i][j+1]==1){dfs(a,b,i,j+1);}
        if(j>0 && !vis[i][j-1] && b[i][j-1]==1){dfs(a,b,i,j-1);}
    
    }
    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        n=a.size();m=a[0].size();vis.resize(n,vector<int>(m,0));int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==1 && !vis[i][j]){
                  t=true; dfs(a,b,i,j);
                    if(t){ans++;}
                }
            }
        }
        return ans;
    }
};