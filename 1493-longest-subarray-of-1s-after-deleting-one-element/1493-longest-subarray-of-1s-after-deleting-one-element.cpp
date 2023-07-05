class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lst=0,st=0,ans=0,n=nums.size();
        bool b=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){st++;}
            else{
                b=true;
                if(st>0 && i+1<n && nums[i+1]==1){
                    ans=max(ans,lst+st);
                    lst=st;st=0;
                    continue;
                }
                else{
                    ans=max(ans,lst+st);lst=0;st=0;
                }
            }
        }
        ans=max(ans,lst+st);
        if(b==false){ans--;}
        return ans;
    }
};