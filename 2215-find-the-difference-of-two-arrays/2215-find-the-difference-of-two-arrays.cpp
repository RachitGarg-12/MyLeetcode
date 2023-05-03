class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> m1,m2;
        vector<vector<int>> ans(2);
        for(auto i:nums1){m1.insert(i);}
        for(auto i:nums2){m2.insert(i);}
        for(auto i:m2){if(m1.find(i)==m1.end()){ans[1].push_back(i);}}
        for(auto i:m1){if(m2.find(i)==m2.end()){ans[0].push_back(i);}}
        return ans;
    }
};