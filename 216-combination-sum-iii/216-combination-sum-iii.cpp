class Solution {
public:
    void allcombi(int k, int n,int i,vector<vector<int>> &ans,vector<int> cur){
        if(n==0 && k==0){ans.push_back(cur);return;}
        if(k==0){return;}
        if(i>9){return;}
        cur.push_back(i);
        allcombi(k-1,n-i,i+1,ans,cur);
        cur.pop_back();
        allcombi(k,n,i+1,ans,cur);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
          if(n < (k*(k+1))/2){return {};}
        vector<vector<int>> ans;vector<int> cur;
        allcombi(k,n,1,ans,cur);
        return ans;
    }
};