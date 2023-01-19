class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){dp[i][j]=grid[i][j];continue;}
                else if(i==0){dp[i][j]=grid[i][j]+dp[i][j-1];}
                else if(j==0){dp[i][j]=grid[i][j]+dp[i-1][j];}
                else{
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,left);
            
                }
            }
        }
        return dp[n-1][m-1];
    }
};