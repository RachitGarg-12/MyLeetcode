class Solution {
public:
    int n;
    int f(int i,vector<int>& a,int j,vector<vector<int>> &dp){
        if(i==n || i<j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=f(i+1,a,j,dp);
        if(a[i]>a[j]){ans=max(ans,1+f(i+1,a,i,dp));}
        return dp[i][j]=ans;
    }
    int lengthOfLIS(vector<int>& a) {
        n=a.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i<j){continue;}
                int ans=dp[i+1][j];
                if(a[i]>a[j]){ans=max(ans,1+dp[i+1][i]);}
                dp[i][j]=ans;   
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
           res=max(res,1+dp[i][i]);
        }
        return res;
    }
};