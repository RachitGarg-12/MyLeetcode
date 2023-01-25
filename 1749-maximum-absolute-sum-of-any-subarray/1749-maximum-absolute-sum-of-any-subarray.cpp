class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = INT_MIN,ans2 = INT_MAX;
        int cur1 = 0, mx = 0,mn = 0,cur2 = 0;
        for(auto &i: nums){
            cur1 += i;
            cur2 += i;
            if(ans2>cur2){
                ans2= cur2;
            }
            if(ans1<cur1){
                ans1 = cur1;
            }
            if(cur1<0)cur1 = 0;
            if(cur2>0)cur2 = 0;
        }
        return max(abs(ans2),ans1);
    }
};