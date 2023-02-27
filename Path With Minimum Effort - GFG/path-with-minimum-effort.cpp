//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dirx[4]={-1,0,0,1};
        int diry[4]={0,-1,1,0};
        while(!pq.empty()){
            auto t=pq.top();pq.pop();
            int d=t.first;
            int x=t.second.first;
            int y=t.second.second;
            if(x==n-1 && y==m-1){return d;}
            for(int i=0;i<4;i++){
                int curx=x+dirx[i],cury=y+diry[i];
                if(curx>=0 && curx<n && cury>=0 && cury<m){
                    int effort=max(d,abs(heights[curx][cury]-heights[x][y]));
                    if(effort<dist[curx][cury]){
                        dist[curx][cury]=effort;
                        pq.push({effort,{curx,cury}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends