class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int left,vector<vector<int>> &dp,int n,int k){
        if(left==0 && i==n){return 1;}
        if(i>=n || left<0){return 0;}
        if(dp[i][left]!=-1){return dp[i][left]%mod;}
        int ans=0;
        for(int j=1;j<=k;j++){
            ans=(ans%mod + f(i+1,left-j,dp,n,k)%mod ) %mod;
        }
        return dp[i][left]=ans;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return f(0,target,dp,n,k);
    }
};