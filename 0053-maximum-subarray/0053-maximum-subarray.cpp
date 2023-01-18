class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int dp[n];//max subarray sum ending at i from [0..i]
        int ans=dp[0]=a[0];//base case
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+a[i],a[i]);
            ans=max(ans,dp[i]);
        }      
        return ans;
    }
};