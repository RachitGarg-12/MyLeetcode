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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,nums1,nums2,dp);
    }
};