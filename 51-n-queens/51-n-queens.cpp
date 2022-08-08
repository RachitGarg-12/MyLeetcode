class Solution {
public:

    void solve(vector<vector<string>> &ans,int n,vector<string> board,int col,vector<bool> &rowdone,vector<bool> &up,vector<bool> &down){
        if(col==n){ ans.push_back(board);return;}
        
        for(int i=0;i<n;i++){
           if(rowdone[i]==true) continue;
           if(down[col+i]==true) continue;
           if(up[(n-1)-(col-i)]==true) continue;
            rowdone[i]=true;down[col+i]=true;up[(n-1)-(col-i)]=true;
            board[i][col]='Q';
            solve(ans,n,board,col+1,rowdone,up,down);
            board[i][col]='.';
             rowdone[i]=false;down[col+i]=false;up[(n-1)-(col-i)]=false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
    vector<bool> rowdone(n,false);
    vector<bool> up((2*n)-1,false);
    vector<bool> down((2*n)-1,false);
        vector<vector<string>> ans;
        string s(n,'.');vector<string> board(n);
        for(int i=0;i<n;i++){board[i]=s;}
        solve(ans,n,board,0,rowdone,up,down);
        return ans;
    }
};