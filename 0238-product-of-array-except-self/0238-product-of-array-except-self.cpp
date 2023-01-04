class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int pro=1;
        int n=nums.size();
        for(auto i:nums){
            if(i==0){zero++;}
            else{pro*=i;}
        }
        vector<int> ans(n);
        if(zero==0){
           for(int i=0;i<n;i++){
               ans[i]=pro/nums[i];
           }
        }
        if(zero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){ans[i]=pro;}
                else{ans[i]=0;}
            }
        }
        if(zero>1){
           for(int i=0;i<n;i++){
               ans[i]=0;
           } 
        }
        return ans;
    }
};