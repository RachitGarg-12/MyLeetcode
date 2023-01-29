class Solution {
public:
int n,m;string a,b;
int dp[1001][1001];
int rec(int i,int j){
     if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j]){return 1+rec(i-1,j-1);}
    return dp[i][j]=max(rec(i-1,j),rec(i,j-1));
                   
}
    int longestCommonSubsequence(string text1, string text2) {
        a=text1,b=text2;n=a.size(),m=b.size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1);
    }
};