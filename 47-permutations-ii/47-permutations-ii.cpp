class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());ans.push_back(nums);
        vector<int> prev=nums;
        while(next_permutation(nums.begin(),nums.end())){
            if(nums==prev){continue;}
            ans.push_back(nums);prev=nums;
        }
        return ans;
    }
};