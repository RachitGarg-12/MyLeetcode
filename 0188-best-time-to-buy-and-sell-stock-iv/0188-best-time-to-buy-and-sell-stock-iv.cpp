class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        int dp[n+1][2][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int take=k;take>=1;take--){
                    int profit=0;
                    if(buy){
                        profit=max((-a[i])+dp[i+1][0][take],dp[i+1][1][take]);
                    }
                    else{
                        profit=max(a[i]+dp[i+1][1][take-1],dp[i+1][0][take]);
                    }
                   dp[i][buy][take]=profit;
                }
            }
        }
        return dp[0][1][k];        
    }
};