class Solution {
public:
    string s1,s2;int n;
    vector<vector<int>> dp;
    int rec(int i,int j){
        if(i>=n || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){ans=1+rec(i+1,j+1);}
        ans=max(ans,rec(i+1,j));
        ans=max(ans,rec(i,j+1));
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        n=s.size();s1=s;reverse(s.begin(),s.end());s2=s;
        dp.resize(n,vector<int>(n,-1));
        return rec(0,0);
    }
};