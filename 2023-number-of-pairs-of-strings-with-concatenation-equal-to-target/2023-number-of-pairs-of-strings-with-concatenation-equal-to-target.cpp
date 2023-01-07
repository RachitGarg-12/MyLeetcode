class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int m=target.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i].size()+nums[j].size()==m){
                    if(nums[i]+nums[j]==target){ans++;}
                    if(nums[j]+nums[i]==target){ans++;}
                }
            }
        }
        return ans;
    }
};