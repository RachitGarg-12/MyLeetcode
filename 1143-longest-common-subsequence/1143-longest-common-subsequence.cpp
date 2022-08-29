class Solution {
public:
int n,m;string a,b;
int dp[1001][1001];
int rec(int i,int j){
    //return the lcs of all a[i...n-1] ans b[j...m-1]
    //pruning 
    //base case
    if(i>=n || j>=m){return 0;}

    //save and compute
    if(dp[i][j]!=-1){return dp[i][j];}
    //compute
    int ans=0;
    ans=max(ans,rec(i+1,j));
    ans=max(ans,rec(i,j+1));
    if(a[i]==b[j]){ans=max(ans,1+rec(i+1,j+1));}

    return dp[i][j]=ans;
}
    int longestCommonSubsequence(string text1, string text2) {
        a=text1,b=text2;n=a.size(),m=b.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};