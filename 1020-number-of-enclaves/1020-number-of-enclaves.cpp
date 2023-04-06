class Solution {
public:
    int n,m;

    void dfs(int i,int j,vector<vector<int>>& board,vector<vector<int>> &vis){
        vis[i][j]=1;
        if(i-1>=0 && board[i-1][j]==1 && !vis[i-1][j]){dfs(i-1,j,board,vis);}
        if(j-1>=0 && board[i][j-1]==1 && !vis[i][j-1] ){dfs(i,j-1,board,vis);}
        if(i+1<n && board[i+1][j]==1&& !vis[i+1][j]){dfs(i+1,j,board,vis);}
        if(j+1<m && board[i][j+1]==1&& !vis[i][j+1] ){dfs(i,j+1,board,vis);}
        
    }
    int numEnclaves(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j]==1){dfs(i,j,board,vis);}
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]==1){ans++;}
            }
        }   
        return ans;
    }
};