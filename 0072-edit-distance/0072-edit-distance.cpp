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
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){dp[0][j]=j;}
        for(int i=0;i<=n;i++){dp[i][0]=i;}        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){dp[i][j]=dp[i-1][j-1];}
                else{
                int ans=1e9;
                ans=min(ans,1+dp[i][j-1]);//insert cur char of s2 to  s1
                ans=min(ans,1+dp[i-1][j]);//delete cur char of s1
                ans=min(ans,1+dp[i-1][j-1]);//replace cur char of s1 to match with s2
                dp[i][j]=ans;   
                }
            }
        }
        return dp[n][m];
    }
};