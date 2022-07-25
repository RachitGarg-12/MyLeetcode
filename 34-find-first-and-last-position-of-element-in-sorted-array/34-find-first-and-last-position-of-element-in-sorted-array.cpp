class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = lower_bound(nums.begin(),nums.end(),target);
        auto end = upper_bound(nums.begin(),nums.end(),target);
        if(start==nums.end() || *start!=target){return {-1,-1};}
        int st=start-nums.begin();int en=end-nums.begin()-1;
        return {st,en};
    }
};
