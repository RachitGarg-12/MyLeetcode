class Solution {
public:
    int dp[1002];
    int combi(vector<int>& nums, int target){
        if(target==0){return 1;}
        if(dp[target]!=-1){return dp[target];}
        int ways=0;
        for(int it:nums){
        if(it<=target){  ways += combi(nums,target-it);} }
        return dp[target]=ways;
}
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return combi(nums,target);;
    }
};