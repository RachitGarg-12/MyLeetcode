class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;int mx=0;int ans=0;
        for(auto i:nums){m[i]++;}
        for(auto i:m){mx=max(mx,i.second);}
        for(auto i:m){
            if(i.second==mx){ans=max(ans,i.first);}}
        return ans;
    }
};