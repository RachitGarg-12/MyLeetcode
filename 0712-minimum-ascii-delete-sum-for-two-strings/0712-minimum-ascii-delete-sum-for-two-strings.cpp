class Solution {
public:
    int n,m;
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==n || j==m){
            int sum=0;
            while(j<m){sum+=int(s2[j]);j++;}
            while(i<n){sum+=int(s1[i]);i++;}
            return sum;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=0;
        if(s1[i]==s2[j]){ans=f(i+1,j+1,s1,s2,dp);}
        else{ans=min(int(s1[i])+f(i+1,j,s1,s2,dp),int(s2[j])+f(i,j+1,s1,s2,dp));}
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
         n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,s1,s2,dp);
    }
};