class Solution {
public:
    const int mod=1e9+7;
    int n;
    int f(int lasti,int mask,vector<int>& a,vector<vector<int>> &dp){
        if(mask==(1<<n)-1){return 1;}
        if(dp[lasti][mask]!=-1){return dp[lasti][mask];}
        long long ans=0;
        for(int i=0;i<n;i++){
            if(((mask>>i)&1)==0 && (mask==0 || a[i]%a[lasti]==0 || a[lasti]%a[i]==0)){
                ans=(ans%mod + f(i,mask|(1<<i),a,dp)%mod)%mod;
            }
        }
        return dp[lasti][mask]=ans;
    }
        
    int specialPerm(vector<int>& a) {
        n=a.size();
        int ans=0;
        int l=1<<n;
        vector<vector<int>> dp(n+1,vector<int>(l+6,-1));
        sort(a.begin(),a.end());
        return f(0,0,a,dp);
    }
};