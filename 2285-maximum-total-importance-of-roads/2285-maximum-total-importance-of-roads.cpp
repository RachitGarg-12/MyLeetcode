class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<pair<int,int>> sz;
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            sz.push_back({adj[i].size(),i});
        }
        sort(sz.begin(),sz.end());
        int val=n;
        unordered_map<int,int>value;
        int m=sz.size();
        for(int i=m-1;i>=0;i--){
            value[sz[i].second]=val;val--;
        }
        long long ans=0;
        for(auto i:roads){
            ans+= value[i[0]]+value[i[1]];
        }
        return ans;
    }
};