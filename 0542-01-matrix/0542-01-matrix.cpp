class Solution {
public:
 
        int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};

bool isValid(int row,int col,int m,int n)
{
    if(row<0||col<0||row>=m||col>=n)return false;
    
    return true;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
{
    int INF=1e7;
    int m=mat.size();
    int n=mat[0].size();
    queue<pair<int,int>>q;
    
    //Vector To Store Minimum Distance From (i,j) to 0
    vector<vector<int>>dist(m,vector<int>(n,INF));
    // vis[i][j] -> 1 if we already visited (i, j), 0 otherwise
    vector<vector<int>>vis(m,vector<int>(n,0));
    
    //Traverse Over The Whole Matrix And push all (i,j) into queue if mat[i][j]==0
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
               q.push({i, j});
               // the shortest distance form any 0 to 0 is 0
               dist[i][j] = 0;
               // Also mark the cell as visited
               vis[i][j] = 1;
            }
        }
    }
    
    while(!q.empty())
    {
        
         pair<int,int>p=q.front();
         int i = p.first;
         int j = p.second;
         q.pop();
        
         for(int k=0;k<4;k++)
         {
             // if this Neighbour cell Is not visited and lies inside the matrix
             if(isValid(i+di[k],j+dj[k],m,n) && !vis[i+di[k]][j+dj[k]])
             {
                //Update The Distance of the neighbour cell
                dist[i+di[k]][j+dj[k]] = min(dist[i+di[k]][j+dj[k]], 1 + dist[i][j]);
                // mark this neighbour cell visited
                vis[i+di[k]][j+dj[k]] = 1;
                // push neighbour cell into the queue to continue the bfs
                q.push({i+di[k], j+dj[k]});
             }
         }
    }
    return dist;
    
    }
};