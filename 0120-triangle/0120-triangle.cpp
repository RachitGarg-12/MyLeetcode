class Solution {
public:
    int n,m;
    int f(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==n-1){return triangle[i][j];}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=triangle[i][j]+min(f(i+1,j+1,triangle,dp),f(i+1,j,triangle,dp));
        return dp[i][j]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size(),m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,triangle,dp);
    }
};