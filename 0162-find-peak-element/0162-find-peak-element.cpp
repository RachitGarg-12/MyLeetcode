class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int l=0,r=n-1;
        int ans;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m==0){
                if(nums[m+1]<nums[m]){return m;}
                else{return m+1;}
            }
            if(m==n-1){
                if(nums[m-1]<nums[m]){return m;}
                else{return m-1;}
            }
            if(nums[m]>nums[m+1] && nums[m]>nums[m-1]){ans=m;break;}
            else if(nums[m+1]>nums[m]){l=m+1;}
            else if(nums[m-1]>nums[m]){r=m-1;}
        }
        return ans;
    }
};