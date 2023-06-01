class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int n=a.size(),m=a[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1][j-1]=='1'){
                   dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};