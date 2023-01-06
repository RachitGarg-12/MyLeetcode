class Solution {
public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0)return -1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({1,{0,0}});
        int dx[8]={-1,-1,0,1,1,1,0,-1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};
        while(!pq.empty()){
            auto top=pq.front();
            pq.pop();
            int currdis=top.first;
            int currx=top.second.first;
            int curry=top.second.second;
            if(currx==n-1 && curry==m-1)return currdis;
            for(int i=0;i<8;i++){
                int nextx=currx+dx[i];
                int nexty=curry+dy[i];
                if(nextx>=0 && nextx<n && nexty>=0 && nexty<m && grid[nextx][nexty]==0 && currdis+1<dist[nextx][nexty])                 {
                    //updated distance for current cell
                    dist[nextx][nexty]=currdis+1;
                    pq.push({currdis+1,{nextx,nexty}});
                }
            }
        }
        return -1;
    }
};