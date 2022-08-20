class Solution {
public:
    int rec(int i,vector<int>& a,int n,vector<int> &dp){
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e6;
        for(int j=1;j<=a[i];j++){
            int temp= 1+ rec(i+j,a,n,dp);
            ans=min(ans,temp);
        }
        
        return dp[i]=ans;
    }
    int jump(vector<int>& a) {
        int n=a.size();vector<int> dp(n,-1);
        return rec(0,a,n,dp);
    }
};