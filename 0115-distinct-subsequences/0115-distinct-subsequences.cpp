class Solution {
public:
    int f(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(j<0){return 1;}
        if(i<j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ntake=f(i-1,j,s,t,dp);
        int take=0;
        if(s[i]==t[j]){take=f(i-1,j-1,s,t,dp);}
        return dp[i][j]=take+ntake;
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s,t,dp);
    }
};