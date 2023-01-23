class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> m,l;
        for(auto i:trust){
            m[i[0]]=i[1];
            l[i[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(m[i]==0){
              if(l[i]!=n-1){return -1;}
                return i;}
        }
        return -1;
    }
};