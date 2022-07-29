class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();     
      vector<int> next(n+1,0) , curr(n+1,0);
        //dp[i][prev] , lis till index i from index i-1
      for(int ind=n-1;ind>=0;ind--){
          for(int pre=ind-1;pre>=-1;pre--){
          curr[pre+1]=0+next[pre+1];
          if(pre==-1 || nums[ind]>nums[pre]){
          curr[pre+1]=max(curr[pre+1],1+next[ind+1]);
        }
          }
         next=curr;
      }
    return curr[0];
    }
};