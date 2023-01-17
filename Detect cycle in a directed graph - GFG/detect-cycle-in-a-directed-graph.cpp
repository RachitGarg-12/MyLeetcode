//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(dfs(j,adj,vis,pathvis))return true;
            }
            else if(pathvis[j]){return true;}
        }
        pathvis[i]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends