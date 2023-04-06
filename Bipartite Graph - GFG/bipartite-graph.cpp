//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>graph[]){
         vector<int> color(n,-1);
        for(int i=0;i<n;i++){
         if(graph[i].size()>0 && color[i]==-1){
          queue<int> q;
          q.push(i);color[i]=0;
        while(!q.empty()){
            int k=q.front();
            q.pop();
            int cn=(color[k]==0)?1:0;
            for(auto j:graph[k]){
                if(color[j]==-1){
                    color[j]=cn;
                    q.push(j);
                }
                else{
                    if(color[j]!=cn)return false;
                }
            }
        }
         }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends