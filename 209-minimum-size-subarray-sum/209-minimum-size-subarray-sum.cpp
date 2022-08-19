 class Solution {
public:
    bool predicate(int target, vector<int>& nums,int m, vector<int> &pref){
        
        for(int i=0;i<=nums.size()-m;i++){
            int temp;
            if(i==0){temp=pref[i+m-1];}
            else{temp=pref[i+m-1]-pref[i-1];}
            if(temp>=target){return true;}
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);pref[0]=nums[0];
        for(int i=1;i<n;i++){pref[i]=pref[i-1]+nums[i];}
        int l=1,r=nums.size(),ans=r;bool pos=false;
        while(l<=r){
            int m=l+(r-l)/2;
            if(predicate(target,nums,m,pref)){pos=true;ans=m;r=m-1;}
            else{l=m+1;}
        }
        if(pos==false){return 0;}
        return ans;
    }
};