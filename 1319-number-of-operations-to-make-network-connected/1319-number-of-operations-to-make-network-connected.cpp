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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ext=0;
        for(auto i:connections){
            if(ds.findUpar(i[0])==ds.findUpar(i[1])){ext++;continue;}//if already same parent we dont need this edge as they are already connected
            //we only take the edges which are needed to form connected component
            ds.unionBySize(i[0],i[1]);
        }
        int req=-1;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){req++;}
        }
        if(ext<req){return -1;}
        return req;
    }
};