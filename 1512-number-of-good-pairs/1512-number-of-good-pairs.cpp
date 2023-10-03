class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){m[i]++;}
        int ans=0;
        for(auto i:m){
            int n=i.second;
            if(n){ans+=(n*(n-1))/2;}
        }
        return ans;
    }
};