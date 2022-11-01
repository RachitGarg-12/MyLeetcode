class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n=a.size();bool b=false;
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        ans.push_back(a[0]);
        int j=0;
        for(int i=1;i<n;i++){
            if(ans[j][1]>=a[i][0]){ans[j][1]=max(ans[j][1],a[i][1]);}
            else{j++;ans.push_back(a[i]);}
        }
        return ans;
    }
};