class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();     
      vector<int> dp(n,1);dp[0]=1;vector<int> hash(n);
        int lastindex=0;
        int ans=1;
      for(int i=1;i<n;i++){
          hash[i]=i;
          for(int j=i-1;j>=0;j--){
              if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                  dp[i]=dp[j]+1;
                  hash[i]=j;}
          }
          if(dp[i]>ans){ans=dp[i];lastindex=i;}
      }
        vector<int> back; back.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            back.push_back(nums[lastindex]);
        }
        reverse(back.begin(),back.end());
        for(auto i:back){cout<<i<<" ";}
        cout<<endl;
        return ans;
    }
    
};