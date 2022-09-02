class Solution {
public:
    int n,m,ans;vector<vector<bool>> vis;bool b=true;
    void dfs(vector<vector<int>>& a,int i,int j){
        vis[i][j]=true;
        if(i==0 || j==0 || i==n-1 || j==m-1){b=false;return;}
        ans++;
        
        if(i>0 && !vis[i-1][j] && a[i-1][j]==1){dfs(a,i-1,j);}
        if(i<n-1 && !vis[i+1][j] && a[i+1][j]==1){dfs(a,i+1,j);}
        if(j<m-1 && !vis[i][j+1] && a[i][j+1]==1){dfs(a,i,j+1);}
        if(j>0 && !vis[i][j-1] && a[i][j-1]==1){dfs(a,i,j-1);}
    
    }
    int numEnclaves(vector<vector<int>>& a) {
        n=a.size();m=a[0].size();
        vis.resize(n,vector<bool>(m,false));
        int res=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(a[i][j]==1 && !vis[i][j]){
                    b=true;ans=0;dfs(a,i,j);
                    if(b){res+=ans;}
                }
            }
           
        }
        return res;
    }
};