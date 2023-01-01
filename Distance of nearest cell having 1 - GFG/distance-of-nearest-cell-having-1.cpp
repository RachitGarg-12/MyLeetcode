//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
         int n,m;
     void bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>& q,vector<vector<int>> &vis,vector<vector<int>> &dis){      
     int drow[]={-1,0,1,0};
     int dcol[]={0,1,0,-1};
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front();
            q.pop();
            int r=p.first.first,c=p.first.second,t=p.second;
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==0) 
                {
                    q.push({{row,col},t+1});
                    vis[row][col]=1;
                    dis[row][col]=t+1;
                }
            }
        }

    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;bool done=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dis[i][j]=0;
                }
            }
        }
       bfs(grid,q,vis,dis);
       return dis;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends