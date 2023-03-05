class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<vector<int>>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(int S=0;S<n;S++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,S});
            vector<int> dist(n,1e9);
            dist[S]=0;
            while(!pq.empty()){
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto i:adj[node]){
                    if(dis+i[1]<dist[i[0]]){
                        dist[i[0]]=dis+i[1];
                        pq.push({dist[i[0]],i[0]});
                    }
                }
            }
            cost[S]=dist;
        }
        int ans=1e9,res=-1;
        for(int i=0;i<n;i++){
           int cur=0;
           for(int j=0;j<n;j++){
               if(cost[i][j]<=distanceThreshold){cur++;}
           } 
           if(cur<=ans){res=i;ans=cur;}
        }
        return res;
    }
};