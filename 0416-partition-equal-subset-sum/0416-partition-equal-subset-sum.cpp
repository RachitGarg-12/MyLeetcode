class Solution {
public:
    bool f(int i,int sum,vector<int>& nums,vector<vector<int>> &dp){
        if(sum==0){return true;}
        if(i<0 || sum<0){return false;}
        if(dp[i][sum]!=-1){return dp[i][sum];}
        return dp[i][sum]=(f(i-1,sum,nums,dp)||f(i-1,sum-nums[i],nums,dp));
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2){return false;}
        sum/=2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,nums,dp);
    }
};