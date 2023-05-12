class Solution {
public:
    int n;
    long long f(vector<vector<int>>& q,int i,vector<long long> &dp){
        if(i>=n){return 0;}
        if(dp[i]!=-1)return dp[i];
        long long ans=f(q,i+q[i][1]+1,dp)+q[i][0];
        ans=max(ans,f(q,i+1,dp));
        return dp[i]=ans;
    }
    long long mostPoints(vector<vector<int>>& q) {
        n=q.size();
        vector<long long> dp(n,-1);
        return f(q,0,dp);
    }
};