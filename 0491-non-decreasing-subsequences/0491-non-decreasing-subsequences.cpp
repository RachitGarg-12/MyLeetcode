class Solution {
public:
    set<vector<int>> ans;
    int n;
    void f(int i,vector<int> &a,vector<int> temp){
        if(i==n){
            if(temp.size()>=2){ans.insert(temp);}
            return;
        }
        int l=temp.size();
        f(i+1,a,temp);
        if(l==0 || a[i]>=temp[l-1]){
              temp.push_back(a[i]);
              f(i+1,a,temp); 
        }
        
        
    }
    vector<vector<int>> findSubsequences(vector<int>& a) {
        n=a.size();
        f(0,a,{});
        vector<vector<int>> res;
        for(auto i:ans){res.push_back(i);}
        return res;
    }
};