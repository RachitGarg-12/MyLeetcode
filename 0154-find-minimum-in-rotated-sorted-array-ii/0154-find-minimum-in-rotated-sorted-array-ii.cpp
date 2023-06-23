class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]){l=m+1;}
            else if(nums[m]<nums[r]){r=m;}
            else{r--;}
        }
        return nums[l];        
    }
};