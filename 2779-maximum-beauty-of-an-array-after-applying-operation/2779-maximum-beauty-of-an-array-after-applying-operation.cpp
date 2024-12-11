class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=nums[0];i<=nums[n-1];i++){
            int l=max(0,i-k),r=i+k;
            int left=lower_bound(nums.begin(),nums.end(),l)-nums.begin();
            int right=upper_bound(nums.begin(),nums.end(),r)-nums.begin();
            ans=max(ans,right-left);
        }
        return ans;
    }
};