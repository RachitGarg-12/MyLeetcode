class DisjointSet{
    public:
    vector<int> rank,parent,size;
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

class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){edges.push_back({i+1,j+1});}
            }
        }
        DisjointSet ds(n);
        unordered_set<int> par;
        for(auto i:edges){
            ds.unionBySize(i[0],i[1]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(ds.parent[i]==i){ans++;}
        }
        return ans;
    }
};