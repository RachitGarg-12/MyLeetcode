class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
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
            if(stops==k+1){continue;}
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