class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}
        if(n==3){return max(nums[0],max(nums[1],nums[2]));}
        int prev2=nums[0];int prev=max(nums[1],nums[0]);
        for(int i=2;i<n-1;i++){
            int curr=max(prev2+nums[i],prev);
            prev2=prev;prev=curr;
        }
        int pre2=nums[1];int pre=max(nums[1],nums[2]);
         for(int i=3;i<n;i++){
            int cur=max(pre2+nums[i],pre);
            pre2=pre;pre=cur;
        }
        
       return max(prev,pre); 
    }
};