class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        if(nums[r]<target){return -1;}
        int ans=-1;
        while(l<=r){
            int m= l+(r-l)/2;
            if(nums[m]>=target){ans=m;r=m-1;}
            else{l=m+1;}
        }
        if(nums[ans]==target){return ans;}
        return -1;
        
    }
};