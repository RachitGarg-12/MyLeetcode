class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        int dp[n+1][2*k+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
                    int profit=0;
                    if(trans%2==0){
                        profit=max((-a[i])+dp[i+1][trans+1],dp[i+1][trans]);
                    }
                    else{
                        profit=max(a[i]+dp[i+1][trans+1],dp[i+1][trans]);
                    }
                   dp[i][trans]=profit;
            }
        }
        return dp[0][0];   
    }
};