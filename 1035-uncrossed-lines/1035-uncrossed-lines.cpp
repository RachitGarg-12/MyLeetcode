class Solution {
public:
    int n,m;
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        if(i==n || j==m){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=0;
        if(nums1[i]==nums2[j]){ans=1+f(i+1,j+1,nums1,nums2,dp);}
        ans=max(ans,f(i+1,j,nums1,nums2,dp));
        ans=max(ans,f(i,j+1,nums1,nums2,dp));
        return dp[i][j]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<m;i++){dp[n][i]=0;}
        for(int i=0;i<n;i++){dp[i][m]=0;}
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
               int ans=0;
               if(nums1[i]==nums2[j]){ans=1+dp[i+1][j+1];}
               ans=max(ans,dp[i+1][j]);
               ans=max(ans,dp[i][j+1]);
               dp[i][j]=ans;
            }
        }
        return dp[0][0];
        
    }
};