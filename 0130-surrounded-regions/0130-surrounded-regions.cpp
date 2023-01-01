class Solution {
public:
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,-1,0,1};

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis){
             vis[row][col]=1;
              int m = board.size();   // rows
              int n = board[0].size(); //cols
             for(int i=0;i<4;i++){
                 int nrow = row+delrow[i];
                 int ncol = col+delcol[i];
                 if(nrow>=0 && ncol >=0 && nrow<m && ncol<n &&
                 vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                     dfs(nrow,ncol,board,vis);
                 }
             }
    }
    void solve(vector<vector<char>>& board) {
         int m = board.size();   // rows
         int n = board[0].size(); //cols
         vector<vector<int>> vis(m,vector<int>(n,0));
         //   Checking on left and right sides
         for(int j=0;j<n;j++){
             if(vis[0][j]!=1 && board[0][j]=='O'){
                 dfs(0,j,board,vis);
             }
             if(vis[m-1][j]!=1 && board[m-1][j]=='O'){
                 dfs(m-1,j,board,vis);
             }
         }
         //Checking on the first and last row Boundary
         for(int i=0;i<m;i++){
             if(vis[i][0]!=1 && board[i][0]=='O'){
                 dfs(i,0,board,vis);
             }
             if(vis[i][n-1]!=1 && board[i][n-1]=='O'){
                 dfs(i,n-1,board,vis);
             }
         }
         //Replacing X with O
         for(int i=0;i<m;i++){
             for(int j =0;j<n;j++){
                   if(vis[i][j]!=1 && board[i][j]=='O'){
                       board[i][j] = 'X';
                   }
             }
         }
    }
};