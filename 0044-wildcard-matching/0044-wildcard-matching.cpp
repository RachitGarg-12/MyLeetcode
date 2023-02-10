class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*'){dp[0][i]=1;}
            else{break;}
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){dp[i][j]=dp[i-1][j-1];}
                else if(p[j-1]=='*'){dp[i][j]=(dp[i][j-1]|dp[i-1][j]);}   
            }
        }
        return dp[n][m];
    }
};