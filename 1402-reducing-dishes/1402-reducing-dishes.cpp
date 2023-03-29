class Solution {
public:
    int n;
    int f(int i,int ele,vector<int>& a, vector<vector<int>> &dp){
        if(i>=n){return 0;}
        if(dp[i][ele]!=-1){return dp[i][ele];}
        int ans=0;
        if(a[i]<=0){
            ans=f(i+1,ele,a,dp);
        }
        ans=max(ans,a[i]*(ele+1)+f(i+1,ele+1,a,dp));
        return dp[i][ele]=ans;
    }
    int maxSatisfaction(vector<int>& a) {
        n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,a,dp);
    }
};