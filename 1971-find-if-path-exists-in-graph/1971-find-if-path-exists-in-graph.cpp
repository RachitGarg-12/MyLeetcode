class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        stack<int> q;
        q.push(source);vis[source]=true;
        while(!q.empty()){
            int cur=q.top();
            q.pop();
            if(cur==destination)return true;
            for(auto i:adj[cur]){
                   if(vis[i]==false){vis[i]=true;q.push(i);}
            } 
        }
        return false; 
    }
};