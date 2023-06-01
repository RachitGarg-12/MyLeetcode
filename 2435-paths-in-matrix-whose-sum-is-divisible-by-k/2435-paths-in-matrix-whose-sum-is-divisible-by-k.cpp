class Solution {
public:
    int n,m;
    const int mod=1e9+7;
    int rec(int i,int j,int sum,vector<vector<int>>& a,int &k,vector<vector<vector<int>>> &dp){
        sum+=a[i][j];sum%=k;
        if(i==n-1 && j==m-1){
            if(sum==0){return 1;}
            return 0;
        }
        if(dp[i][j][sum]!=-1){return dp[i][j][sum];}
        int ans=0;
        if(i+1<n){ans=(ans%mod+rec(i+1,j,sum,a,k,dp)%mod)%mod;}
        if(j+1<m){ans=(ans%mod+rec(i,j+1,sum,a,k,dp)%mod)%mod;}
        return dp[i][j][sum]=ans%mod;
    }
    int numberOfPaths(vector<vector<int>>& a, int k) {
        n=a.size(),m=a[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return rec(0,0,0,a,k,dp);
    }
};