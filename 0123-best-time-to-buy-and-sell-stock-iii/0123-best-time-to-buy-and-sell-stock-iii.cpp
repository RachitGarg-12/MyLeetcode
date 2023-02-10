class Solution {
public:
    int n;
    int dp[100005][2][3];
    int f(int i,int buy,vector<int>& a,int take){
        if(i==n || take==2){return 0;}
        if(dp[i][buy][take]!=-1){return dp[i][buy][take];}
        int profit=0;
        if(buy){
            profit=max((-a[i])+f(i+1,0,a,take),f(i+1,1,a,take));
        }
        else{
            profit=max(a[i]+f(i+1,1,a,take+1),f(i+1,0,a,take));
        }
        return dp[i][buy][take]=profit;
    }
    int maxProfit(vector<int>& a) {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return f(0,1,a,0);
    }
};