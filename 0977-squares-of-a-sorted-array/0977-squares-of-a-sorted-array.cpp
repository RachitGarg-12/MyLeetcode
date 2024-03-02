class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int fpos=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0){fpos=i;break;}
        }
        int lneg=(fpos==-1)?n-1:fpos-1;
        vector<int> ans;
        while(lneg>=0 && fpos<=n-1 && fpos>lneg){
            if(abs(nums[lneg])>=nums[fpos]){
                ans.push_back(nums[fpos]*nums[fpos]);
                fpos++;
            }
            else{
                ans.push_back(nums[lneg]*nums[lneg]);
                lneg--;                
            }
        }
        while(lneg>=0){
                ans.push_back(nums[lneg]*nums[lneg]);
                lneg--;            
        }
        while(fpos<=n-1 && fpos!=-1){
                ans.push_back(nums[fpos]*nums[fpos]);
                fpos++;            
        }
        return ans;
    }
};