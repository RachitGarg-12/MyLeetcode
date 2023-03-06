//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUpar(int node){
        if(node==parent[node]){return node;}
        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int upu = findUpar(u);
        int upv = findUpar(v);
        if(upu==upv){return;}
        if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upu]>rank[upv]){
           parent[upv]=upu;
        }
        else{
           parent[upv]=upu;
           rank[upu]++; 
        }
    } 
    void unionBySize(int u,int v){
        int upu = findUpar(u);
        int upv = findUpar(v);
        if(upu==upv){return;}
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int wt=it[1];
                int adjnode=it[0];
                edges.push_back({wt,{i,adjnode}});
            }
        }
        sort(edges.begin(),edges.end());
        int mst=0;
        DisjointSet ds(V);
        for(auto i:edges){
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;
            if(ds.findUpar(u)!=ds.findUpar(v)){
                ds.unionBySize(u,v);
                mst+=wt;
            }
        }
        return mst;
    }
};
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // vector<int> vis(V,0);
        // pq.push({0,0});
        // int sum=0;
        // while(!pq.empty()){
        //     auto it=pq.top();
        //     pq.pop();
        //     int wt=it.first;
        //     int node=it.second;
        //     if(vis[node]){continue;}
        //     vis[node]=1;
        //     sum+=wt;
        //     for(auto j:adj[node]){
        //         int node2=j[0];
        //         int wt2=j[1];
        //         pq.push({wt2,node2});
        //     }
        // }
        // return sum;

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends