//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        vector<int> minCost(n,1e9);
        minCost[src]=0;
        while(!pq.empty()){
            int c=pq.front().first;
            int node=pq.front().second.first;
            int stops=pq.front().second.second;
            pq.pop();
            if(stops==K+1){continue;}
            for(auto i:adj[node]){
                if(c+i.second<minCost[i.first]){
                    minCost[i.first]=c+i.second;
                    pq.push({minCost[i.first],{i.first,stops+1}});
                }
            }
        }
        if(minCost[dst]==1e9){return -1;}
        return minCost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends