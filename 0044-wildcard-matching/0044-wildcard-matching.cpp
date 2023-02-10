class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(i<0){
            if(j>=0){
                for(int k=0;k<=j;k++){
                    if(p[k]!='*'){return false;}
                }
                return true;
            }
            else{return true;}
        }
       if(j<0){
           if(i<0){return true;}
           return false;
       } 
        if(dp[i][j]!=-1){return dp[i][j];}
       if(s[i]==p[j] || p[j]=='?'){return dp[i][j]=f(i-1,j-1,s,p,dp);}
       else if(p[j]=='*'){return  dp[i][j]=(f(i,j-1,s,p,dp) |f(i-1,j,s,p,dp));}
       return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*'){dp[0][i]=true;}
            else{break;}
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){dp[i][j]=dp[i-1][j-1];}
                else if(p[j-1]=='*'){dp[i][j]=(dp[i][j-1]|dp[i-1][j]);}   
            }
        }
        return dp[n][m];
    }
};