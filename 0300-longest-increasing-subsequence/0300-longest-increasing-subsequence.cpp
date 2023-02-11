class Solution {
public:
    int n;
    // int f(int i,vector<int>& a,int j,vector<vector<int>> &dp){
    //     if(i==n || i<j){return 0;}
    //     if(dp[i][j]!=-1){return dp[i][j];}
    //     int ans=f(i+1,a,j,dp);
    //     if(a[i]>a[j]){ans=max(ans,1+f(i+1,a,i,dp));}
    //     return dp[i][j]=ans;
    // }
    int lengthOfLIS(vector<int>& a) {
        n=a.size();
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};