class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prexor(n);
        prexor[0]=arr[0];
        for(int i=1;i<n;i++){
            prexor[i]=prexor[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto i:queries){
            int l=i[0],r=i[1];
            int cur=(l>0)?prexor[r]^prexor[l-1]:prexor[r];
            ans.push_back(cur);
        }
        return ans;
    }
};