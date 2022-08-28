class Solution {
public:
    int dp[201][201];
    int rec(int r,int c,vector<vector<int>>& grid){
        if(r==0 && c==0){return grid[0][0];}
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=1e9;
        if(r>0){ans=rec(r-1,c,grid)+grid[r][c];}
        if(c>0){ans=min(ans,rec(r,c-1,grid)+grid[r][c]);}
        
        return dp[r][c]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1,grid);
    }
};