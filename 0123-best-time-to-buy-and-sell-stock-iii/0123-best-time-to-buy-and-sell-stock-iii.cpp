class Solution {
public:
    // int f(int i,int buy,vector<int>& a,int take){
    //     if(i==n || take==0){return 0;}
    //     if(dp[i][buy][take]!=-1){return dp[i][buy][take];}
    //     int profit=0;
    //     if(buy){
    //         profit=max((-a[i])+f(i+1,0,a,take),f(i+1,1,a,take));
    //     }
    //     else{
    //         profit=max(a[i]+f(i+1,1,a,take-1),f(i+1,0,a,take));
    //     }
    //     return dp[i][buy][take]=profit;
    // }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int dp[n+1][2][3];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int take=2;take>=1;take--){
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
        return dp[0][1][2];
    }
};