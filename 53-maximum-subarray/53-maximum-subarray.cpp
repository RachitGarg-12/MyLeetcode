class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int dp[n];//dp[i] max subarray sum that includes a[i]
        dp[0]=a[0];int ans=a[0];
        for(int i=1;i<n;i++){
            if(a[i]>dp[i-1] && dp[i-1]<=0){dp[i]=a[i];}
            else{dp[i]=dp[i-1]+a[i];}
           ans=max(ans,dp[i]);
        }
      
        return ans;
        
    }
};