class Solution {
public:
     void allcombination(int i,vector<int> candidates,vector<int> combi,vector<vector<int>> &ans){
        ans.push_back(combi);
        for(int ind=i;ind<candidates.size();ind++){
            combi.push_back(candidates[ind]);
            allcombination(ind+1,candidates,combi,ans);
            combi.pop_back();   
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;vector<int> combi;
        allcombination(0,arr,combi,ans);
        return ans;
    }
};