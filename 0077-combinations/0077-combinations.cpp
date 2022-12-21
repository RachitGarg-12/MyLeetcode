class Solution {
public:
    vector<vector<int>> ans;
    void rec(int cur,vector<int> a,int n,int k){
        if(k-a.size()>n-cur+1){return;}
        rec(cur+1,a,n,k);
        a.push_back(cur);
        if(a.size()==k){ans.push_back(a);return;}
        else{rec(cur+1,a,n,k);}
    }
    vector<vector<int>> combine(int n, int k) {
        rec(1,{},n,k); 
        return ans;
    }
};