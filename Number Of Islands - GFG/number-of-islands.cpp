//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
class Solution {
  public:
    bool isValid(int r,int c,int n,int m){
        return r<n && r>=0 && c<m && c>=0;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<int> ans;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int cnt=0;
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        for(auto &i:operators){
            int r=i[0],c=i[1];
            if(vis[r][c]==1){
                ans.push_back(cnt);continue;
            }
            vis[r][c]=1;
            cnt++;
            for(int i=0;i<4;i++){
                int x=r+dr[i];
                int y=c+dc[i];
                if(isValid(x,y,n,m)){
                    int cur=x*m+y;
                    int adj=r*m+c;
                    if(vis[x][y]==1 && ds.findUpar(cur)!=ds.findUpar(adj)){
                        cnt--;
                        ds.unionBySize(cur,adj);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends