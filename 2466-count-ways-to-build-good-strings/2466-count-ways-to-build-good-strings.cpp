class Solution {
public:
    int mod=1e9+7;
    int rec(int len,int low, int high, int zero, int one,vector<int> &dp){
        if(len>high){return 0;}
        if(dp[len]!=-1){return dp[len];}
        int ans=0;
        if(len>=low && len<=high){ans=1;}
        ans=(ans%mod+rec(len+zero,low,high,zero,one,dp)%mod)%mod;
        ans=(ans%mod+rec(len+one,low,high,zero,one,dp)%mod)%mod;
        return dp[len]=ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return rec(0,low,high,zero,one,dp);
    }
};