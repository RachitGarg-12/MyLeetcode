class Solution {
public:
    int n;
    int f(int i,vector<int>& nums,vector<int> &dp){
       if(i>=n-1){return 0;}
        if(dp[i]!=-1){return dp[i];}
       int ans=1e9; 
       for(int j=i+1;j<n && j<=i+nums[i]; j++){
           ans=min(ans,1+f(j,nums,dp));
       }
       return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};