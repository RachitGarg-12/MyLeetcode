class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j<0){return 1;}
        if(i<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ntake=f(i-1,j,s,t,dp);
        int take=0;
        if(s[i]==t[j]){take=f(i-1,j-1,s,t,dp);}
        return dp[i][j]=take+ntake;
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int j=0;j<=m;j++){dp[0][j]=0;}
        for(int i=0;i<=n;i++){dp[i][0]=1;}
            
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               double ntake=dp[i-1][j];
               double take=0;
               if(s[i-1]==t[j-1]){take=dp[i-1][j-1];}
               dp[i][j]=take+ntake;                
            }
        }
        return (int)dp[n][m];
    }
};