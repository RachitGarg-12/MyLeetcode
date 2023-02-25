//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    stack<int> s;
    void dfs(int i,vector<vector<pair<int,int>>> &adj,vector<int> &vis){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j.first]){dfs(j.first,adj,vis);}
        }
        s.push(i);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
        vector<int> dist(N,1e9);
        dist[0]=0;
        while(!s.empty()){
            int cur=s.top();
            s.pop();
            for(auto i:adj[cur]){
                dist[i.first]=min(dist[i.first],dist[cur]+i.second);
            }
        }
        for(auto &i:dist){if(i==1e9){i=-1;}}
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends