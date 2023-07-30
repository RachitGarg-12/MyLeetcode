class Solution {
public:
    int f(int i,int j,string s,vector<vector<int>> &dp){
        if(i>j){return 0;}
        if(i==j){return 1;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=1+f(i+1,j,s,dp);
        for(int k=i+1;k<=j;k++){
            if(s[k]==s[i]){
                ans=min(ans,f(i,k-1,s,dp)+f(k+1,j,s,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);
    }
};