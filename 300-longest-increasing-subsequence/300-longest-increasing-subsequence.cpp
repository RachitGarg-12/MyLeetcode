class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();     
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int ind=n-1;ind>=0;ind--){
          for(int pre=ind-1;pre>=-1;pre--){
          dp[ind][pre+1]=0+dp[ind+1][pre+1];
          if(pre==-1 || nums[ind]>nums[pre]){
          dp[ind][pre+1]=max(dp[ind][pre+1],1+dp[ind+1][ind+1]);
        }
          }
      }
    return dp[0][0];
    }
};