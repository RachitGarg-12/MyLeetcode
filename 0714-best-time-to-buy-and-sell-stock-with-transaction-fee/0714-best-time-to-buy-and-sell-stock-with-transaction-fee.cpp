class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(a[i]-fee+dp[i+1][1],dp[i+1][0]);
            dp[i][1]=max((-a[i])+dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][1];        
    }
};