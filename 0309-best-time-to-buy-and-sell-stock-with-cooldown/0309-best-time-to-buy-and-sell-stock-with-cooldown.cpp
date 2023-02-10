class Solution {
public:
   // int dfs(int i , int turn , vector<int>& prices , vector<vector<int>>& dp){
   //      if(i >= prices.size()) return 0;
   //      // 0 for buy
   //      // 1 for sell 
   //      // 2 for last day sold
   //      if(dp[i][turn] != -1){
   //          return dp[i][turn];
   //      }
   //      if(turn == 0){
   //          return dp[i][turn] = max(-prices[i] + dfs(i + 1 , 1 , prices , dp) , dfs(i + 1 , 0 , prices , dp));
   //      }
   //      else if(turn == 1){
   //          return dp[i][turn] = max(prices[i] + dfs(i + 1 , 2 , prices , dp) , dfs(i + 1 , 1 , prices , dp));
   //      }
   //      else{
   //          return dp[i][turn] = dfs(i + 1 , 0 , prices , dp);
   //      }
   //  }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(a[i]+dp[i+2][1],dp[i+1][0]);
            dp[i][1]=max((-a[i])+dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][1];
    }
};