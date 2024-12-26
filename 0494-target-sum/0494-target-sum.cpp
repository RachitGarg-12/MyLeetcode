class Solution {
public:
    int dp[21][10001];
    int ways(int i,vector<int>& nums, int target){
        if(i==nums.size()){
            if(target==0)return 1;
            return 0;
        }
        if(dp[i][1000+target]!=-1){
            return dp[i][1000+target];
        }
        int ans=0;
        ans+=ways(i+1,nums,target+nums[i]);
        ans+=ways(i+1,nums,target-nums[i]);
        return dp[i][1000+target]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return ways(0,nums,target);
    }
};