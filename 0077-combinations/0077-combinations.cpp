class Solution {
public:
    map<vector<int>,int> m;
    void rec(int cur,vector<int> a,int n,int k){
        if(k-a.size()>n-cur){return;}
        if(a.size()==k){m[a]=1;return;}
        for(int i=cur+1;i<=n;i++){
            a.push_back(i);
            rec(i,a,n,k);
            a.pop_back();
            rec(i,a,n,k);
        } 
    }
    vector<vector<int>> combine(int n, int k) {
        rec(0,{},n,k);
        vector<vector<int>> ans;
        for(auto i:m){
            ans.push_back(i.first);
        }
        return ans;
    }
};