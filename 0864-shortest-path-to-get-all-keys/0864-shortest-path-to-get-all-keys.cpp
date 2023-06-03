class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<pair<int,int>,pair<int,int>>> q;
        int k=0;
        int sr,sc;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=grid[i][j];
                if(ch=='@'){sr=i;sc=j;}
                else if(ch>='a' && ch<='f'){
                   k|=(1<<(ch-'a'));
                }
            }
        }
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        q.push({{sr,sc},{0,0}});
        int vis[n+1][m+1][k+1];
        memset(vis,0,sizeof(vis));
        vis[sr][sc][0]=1;
        while(!q.empty()){
            auto a=q.front();q.pop();
            int x=a.first.first,y=a.first.second,koi=a.second.first,t=a.second.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m  || grid[nx][ny]=='#'){continue;}
                char ch=grid[nx][ny];
                if(ch>='a' && ch<='f'){
                    int res=(1<<ch-'a')|koi;
                    if(res==k){return t+1;}
                    if(!vis[nx][ny][res]){
                        q.push({{nx,ny},{res,t+1}});
                        vis[nx][ny][res]=1;
                    }
                }
                else if(ch>='A' && ch<='F'){
                    if((koi>>ch-'A')&1){
                        if(!vis[nx][ny][koi]){
                            q.push({{nx,ny},{koi,t+1}});
                            vis[nx][ny][koi]=1;
                        }
                    }
                }
                else{
                    if(!vis[nx][ny][koi]){
                        q.push({{nx,ny},{koi,t+1}});
                         vis[nx][ny][koi]=1;
                    }                    
                }
            }
        }
        return -1;
    }
};