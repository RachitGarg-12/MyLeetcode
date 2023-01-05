class Solution {
public:
    int minDeletion(vector<int>& nums) {
       vector<int>vec;
        int ans=0,s=nums.size(),j=0;
        if(s==1)
        return 1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(j%2==0){
                if(nums[i]==nums[i+1]){
                     ans++;
                     s--;
                     continue;
                }
            }
            j++;
        }

        if(s%2==1)
         ans++;

         return ans;
    }
};