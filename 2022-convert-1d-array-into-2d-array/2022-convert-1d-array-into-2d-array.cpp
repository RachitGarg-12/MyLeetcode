class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int l=original.size();
        if(m*n!=l){return {};}
        vector<vector<int>> ans(m,vector<int>(n));
        int col=0;
        for(int i=0;i<l;i++){
            ans[i/n][col%n]=original[i];
            col++;
        }
        return ans;
    }
};