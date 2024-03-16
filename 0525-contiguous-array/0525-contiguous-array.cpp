class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),n1=0,n0=0,ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){n0++;}
            else{n1++;}
            if(mp.find(n1-n0)!=mp.end()){
                ans=max(ans,i-mp[n1-n0]);
            }
            else{
                mp[n1-n0]=i;
            }
        }
        return ans;
    }
};