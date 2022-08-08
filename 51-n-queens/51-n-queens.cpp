class Solution {
public:
    bool safe(int col,int row,vector<string> board,int n){
        int tempro=row,tempco=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            col--;row--;
        }
        row=tempro,col=tempco;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            col--;row++;
        }
         row=tempro,col=tempco;
        while(col--){
            if(board[row][col]=='Q') return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,int n,vector<string> board,int col){
        if(col==n){ ans.push_back(board);return;}
        
        for(int i=0;i<n;i++){
            if(safe(col,i,board,n)){
                board[i][col]='Q';
                solve(ans,n,board,col+1);
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');vector<string> board(n);
        for(int i=0;i<n;i++){board[i]=s;}
        solve(ans,n,board,0);
        return ans;
    }
};