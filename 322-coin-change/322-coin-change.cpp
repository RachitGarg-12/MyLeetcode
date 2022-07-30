class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        if(sum==0){return 0;}
        int dp[n][sum+1];
        for(int t=0;t<=sum;t++){
                if(t%coins[0]==0){dp[0][t]=t/coins[0];}
                else{dp[0][t]=1e9;}
            }
            for(int i=1;i<n;i++){
                for(int t=0;t<=sum;t++){
                    int notake = dp[i-1][t];
                    int take = INT_MAX;
                    if(coins[i]<=t){take = 1 + dp[i][t-coins[i]];}
                    dp[i][t]=min(take,notake);
                }
            }
            
            int ans=dp[n-1][sum];
            if(ans>=1e9){ans=-1;}
        return ans;
    }
};