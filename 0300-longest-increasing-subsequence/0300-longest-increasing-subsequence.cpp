class Solution {
public:
    int n;
    int f(int i,vector<int>& a,int j,vector<vector<int>> &dp){
        if(i==n || i<j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=f(i+1,a,j,dp);
        if(a[i]>a[j]){ans=max(ans,1+f(i+1,a,i,dp));}
        return dp[i][j]=ans;
    }
    int lengthOfLIS(vector<int>& a) {
        n=a.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
           ans=max(ans,1+f(i,a,i,dp));
        }
        return ans;
    }
};