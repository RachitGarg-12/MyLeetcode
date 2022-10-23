class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        vector<int> ans(2);int n=a.size();
        vector<bool> b(n+1,false);
        for(auto i:a){if(b[i]==true){ans[0]=i;}
                     b[i]=true;}
        for(int i=1;i<=n;i++){if(b[i]==false){ans[1]=i;}}
    
    return ans;
    }
};