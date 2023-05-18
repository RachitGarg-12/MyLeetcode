class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        for(auto i:edges){
            indeg[i[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){ans.push_back(i);}
        }
        return ans;
    }
};