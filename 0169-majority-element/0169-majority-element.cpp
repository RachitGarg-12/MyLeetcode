class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;int mx=0;int ans=0;
        for(auto i:nums){m[i]++;}
        for(auto i:m){
            if(i.second>=mx){ans=max(ans,i.first);mx=i.second;}}
        return ans;
    }
};