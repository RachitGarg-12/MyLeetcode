class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> m(n);
        for(auto i:roads){
            m[i[0]].insert(i[1]);
            m[i[1]].insert(i[0]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            unordered_set<int> temp=m[i];
            int p=temp.size();
            for(int j=i+1;j<n;j++){
                int q=m[j].size();
                if(temp.count(j)>0){
                    ans=max(ans,p+q-1);
                }
                else{ans=max(ans,p+q);}
            }
        }
        return ans;
    }
};