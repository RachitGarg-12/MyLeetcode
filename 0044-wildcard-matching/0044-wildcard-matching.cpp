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
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s,p,dp);
    }
};