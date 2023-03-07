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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int num=0;
        map<string,int> m;
        unordered_map<int,string> par;
        for(auto i:accounts){
            for(int j=1;j<i.size();j++){
                if(m.find(i[j])==m.end()){
                    m[i[j]]=num;
                    par[num]=i[0];
                    num++;
                }
            }
        }
        int l=m.size();
        DisjointSet ds(l);
        for(auto i:accounts){
            for(int j=1;j<i.size()-1;j++){
                ds.unionBySize(m[i[j]],m[i[j+1]]);
                // cout<<m[i[j]]<<" "<<m[i[j+1]]<<endl;
            }            
        }
        int ni=0;
        unordered_map<int,int> ind;
        for(int i=0;i<num;i++){
            // cout<<i<<" "<<ds.parent[i]<<endl;
            if(ind.find(ds.findUpar(i))==ind.end()){
                ind[ds.findUpar(i)]=ni;
                ni++;
            }
        }
        vector<vector<string>> ans(ni);
        for(auto i:m){
            int j=ind[ds.findUpar(i.second)];
            if(ans[j].size()==0){
                ans[j].push_back(par[i.second]);
            }
            ans[j].push_back(i.first); 
        }
        return ans;
    }
};