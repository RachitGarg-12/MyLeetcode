class Solution {
public:
    bool f(int i,int sum,vector<int>& nums,int n,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(i==n-1) return (sum==nums[i]);
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=false;
        if(nums[i]<=sum) take= f(i+1,sum-nums[i],nums,n,dp);
        bool nottake = f(i+1,sum,nums,n,dp);
        
        return dp[i][sum]= take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();int tot=0;
        for(int i:nums) tot+= i;
        if(tot%2) return false;
      vector<vector<int>> dp(n,vector<int>(tot+1,-1));

        return f(0,tot/2,nums,n,dp);
    }
};