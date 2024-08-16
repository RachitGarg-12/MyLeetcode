class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        int ans=0;
        int small=arrays[0][0],large=arrays[0][arrays[0].size()-1];
        for(int i=1;i<m;i++){
            ans=max(ans,(arrays[i][arrays[i].size()-1])-small);
            ans=max(ans,large-arrays[i][0]);
            small=min(small,arrays[i][0]);
            large=max(large,arrays[i][arrays[i].size()-1]);
        }
        return ans;
    }
};