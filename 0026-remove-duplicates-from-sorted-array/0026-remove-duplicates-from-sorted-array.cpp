class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique;
        unique.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
           if(nums[i]!=nums[i-1]){unique.push_back(nums[i]);}
        }
        int l=unique.size();
        for(int i=0;i<l;i++){
            nums[i]=unique[i];
        }
        return l;
    }
};