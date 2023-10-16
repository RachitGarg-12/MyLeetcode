//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
class Solution
{
    bool isValid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {   
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){continue;}
                for(int k=0;k<4;k++){
                    int x=i+dr[k], y=j+dc[k];
                    if(isValid(x,y,n) && grid[x][y]==1){
                        int cell=i*n+j;
                        int newcell= x*n+y;
                        ds.unionBySize(cell,newcell);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){continue;}
                set<int>comp;
                for(int k=0;k<4;k++){
                    int x=i+dr[k], y=j+dc[k];
                    if(isValid(x,y,n) && grid[x][y]==1){
                        comp.insert(ds.findUpar(x*n+y));
                    }
                }
                int sz=1;
                for(auto it:comp){
                    sz+=ds.size[it];
                }
                ans=max(ans,sz);
            }
        }
        
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUpar(i)]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends