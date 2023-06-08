class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,cur=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){cur++;}
            else{mx=max(mx,cur);cur=0;}
        }
        mx=max(mx,cur);
        return mx;
    }
};