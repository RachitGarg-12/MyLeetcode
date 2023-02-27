//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(grid[source.first][source.second]==0 || grid[destination.first][destination.second]==0){return -1;}
        int r1=source.first,c1=source.second;
        int r2=destination.first,c2=destination.second;
        
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{r1,c1}});
        dist[r1][c1]=0;
        int dirx[4]={-1,0,0,1};
        int diry[4]={0,-1,1,0};
        while(!pq.empty()){
            auto t=pq.front();pq.pop();
            int d=t.first;
            int x=t.second.first;
            int y=t.second.second;
            if(x==r2 && y==c2){return d;}
            for(int i=0;i<4;i++){
                int curx=x+dirx[i],cury=y+diry[i];
                if(curx>=0 && curx<n && cury>=0 && cury<m && d+1<dist[curx][cury] && grid[curx][cury]==1){
                    dist[curx][cury]=d+1;
                    pq.push({d+1,{curx,cury}});
                }
            }
        }
        if(dist[r2][c2]==1e9){return -1;}
        return dist[r2][c2];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends