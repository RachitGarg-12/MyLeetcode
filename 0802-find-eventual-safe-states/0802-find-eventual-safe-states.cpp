class Solution {
public:
    //using bfs toposort
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> adjrev(n);
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjrev[it].push_back(i);indeg[i]++;
            }
        }
        queue<int> q;
        vector<int> safe;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){q.push(i);}
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto i:adjrev[node]){
                indeg[i]--;
                if(indeg[i]==0){q.push(i);}
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};