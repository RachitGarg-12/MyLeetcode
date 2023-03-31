class Solution {
public:
		vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
		int orangesRotting(vector<vector<int>>& grid) {
			int n=grid.size();
			int m=grid[0].size();
			vector<vector<int>> vis(n,vector<int>(m,0));
			queue<pair<pair<int,int>,int>>q;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(grid[i][j]==2){
						q.push({{i,j},0});
						vis[i][j]=2;
					}
				}
			}
			int time=0;
			while(!q.empty()){
				auto node=q.front();
				q.pop();
				int t=node.second;
				time=max(time,t);
				for(auto d:dir){
					int new_r=node.first.first+d.first;
					int new_c=node.first.second+d.second;
					if(new_r<n && new_r>=0 && new_c<m && new_c>=0 && vis[new_r][new_c]!=2 && grid[new_r][new_c]==1){
						q.push({{new_r,new_c},t+1});
						vis[new_r][new_c]=2;
					}    
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(grid[i][j]==1 && vis[i][j]!=2) return -1;
				}
			}
			return time;
		}
	};