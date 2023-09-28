class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int e=0,o=n-1;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){ans[e]=nums[i];e++;}
            else{ans[o]=nums[i];o--;}
        }
        return ans;
    }
};