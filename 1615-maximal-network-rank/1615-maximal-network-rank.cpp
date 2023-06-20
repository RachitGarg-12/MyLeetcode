class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indeg(n,0);
        unordered_map<int,set<int>> m;
        for(auto i:roads){
            indeg[i[0]]++;
            indeg[i[1]]++;
            if(i[0]<i[1]){m[i[0]].insert(i[1]);}
            else{m[i[1]].insert(i[0]);}
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            set<int> temp=m[i];
            for(int j=i+1;j<n;j++){
                if(temp.find(j)!=temp.end()){
                    ans=max(ans,indeg[i]+indeg[j]-1);
                }
                else{ans=max(ans,indeg[i]+indeg[j]);}
            }
        }
        return ans;
    }
};