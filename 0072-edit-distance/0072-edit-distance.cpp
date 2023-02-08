class Solution {
public:
    int n,m;
    int f(int i,int j,string s1, string s2,vector<vector<int>> &dp){
        if(i<0){return j+1;}
        if(j<0){return i+1;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s1[i]==s2[j]){return 0+f(i-1,j-1,s1,s2,dp);}
        int ans=1e9;
        ans=min(ans,1+f(i,j-1,s1,s2,dp));//insert cur char of s2 to  s1
        ans=min(ans,1+f(i-1,j,s1,s2,dp));//delete cur char of s1
        ans=min(ans,1+f(i-1,j-1,s1,s2,dp));//replace cur char of s1 to match with s2
        return dp[i][j]=ans;
    }
    int minDistance(string s1, string s2) {
        n=s1.size();m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
};