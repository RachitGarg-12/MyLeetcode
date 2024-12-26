class Solution {
public:
    int ways(int i,vector<int>& nums, int target){
        if(i==nums.size()){
            if(target==0)return 1;
            return 0;
        }
        int ans=0;
        ans+=ways(i+1,nums,target+nums[i]);
        ans+=ways(i+1,nums,target-nums[i]);
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return ways(0,nums,target);
    }
};