class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();int tot=0;
        for(int i:nums) tot+= i;
        if(tot%2) return false;
        tot /= 2;
        vector<vector<bool>> dp(n,vector<bool>(tot+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=tot) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int sum=1;sum<=tot;sum++){
             bool take=false;
            if(nums[i]<=sum){take= dp[i-1][sum-nums[i]];}
             bool nottake = dp[i-1][sum];
             dp[i][sum]=take||nottake;
            }
        }
        return dp[n-1][tot];
    }
};