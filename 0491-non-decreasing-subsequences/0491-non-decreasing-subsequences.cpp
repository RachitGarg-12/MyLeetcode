class Solution {
public:
    map<vector<int>,int> m;
    vector<vector<int>> res;
    int n;
    void f(int i,vector<int> &a,vector<int> temp){
        if(i==n){
            if(temp.size()>=2 && m.find(temp)==m.end()){
                res.push_back(temp);m[temp]=1;
            } 
            return;
        }
        int l=temp.size();
        f(i+1,a,temp);
        if(l==0 || a[i]>=temp[l-1]){
              temp.push_back(a[i]);
              f(i+1,a,temp); 
              temp.pop_back();
        }   
    }
    vector<vector<int>> findSubsequences(vector<int>& a) {
        n=a.size();
        f(0,a,{});
        return res;
    }
};