//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &pathvis,vector<int> &check){
        vis[i]=1;
        pathvis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(dfs(j,adj,vis,pathvis,check))return true;
            }
            else if(pathvis[j]){return true;}
        }
        check[i]=1;
        pathvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){ans.push_back(i);}
        }
        return ans;       
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends