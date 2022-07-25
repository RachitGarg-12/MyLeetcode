class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          int l=0,r=nums.size()-1;int st=-1,en=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){st=m;r=m-1;}
            else if(nums[m]<target){l=m+1;}
            else{r=m-1;}
        }
        int lo=0,ro=nums.size()-1;
         while(lo<=ro){
            int m=lo+(ro-lo)/2;
            if(nums[m]==target){en=m;lo=m+1;}
            else if(nums[m]<target){lo=m+1;}
            else{ro=m-1;}
        }
        vector<int> ans={st,en};
        return ans;
    }
};