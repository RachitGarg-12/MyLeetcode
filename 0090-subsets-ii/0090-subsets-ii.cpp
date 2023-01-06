class Solution {
public:
     void allcombination(int i,vector<int> candidates,vector<int> combi,vector<vector<int>> &ans){
        ans.push_back(combi);
        for(int ind=i;ind<candidates.size();ind++){
            if(ind>i && candidates[ind]==candidates[ind-1] ){continue;}
            combi.push_back(candidates[ind]);
            allcombination(ind+1,candidates,combi,ans);
            combi.pop_back();   
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;vector<int> combi;
        sort(nums.begin(),nums.end());
        allcombination(0,nums,combi,ans);
        return ans;
    }
};