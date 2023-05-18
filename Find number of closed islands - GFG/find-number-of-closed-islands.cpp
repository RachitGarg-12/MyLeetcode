//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:

    int n,m;
    void dfs(int i,int j,vector<vector<int>>& a,vector<vector<int>> &vis,bool &val){
        vis[i][j]=1;
        if(i==0 || i==n-1 ||j==0 || j==m-1){val=false;}
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        for(int it=0;it<4;it++){
            int x=i+dx[it];
            int y=j+dy[it];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && a[x][y]==1){
                dfs(x,y,a,vis,val);
            }
        }
    }
    int closedIslands(vector<vector<int>>& a, int N, int M) {
        n=N;m=M;
        int ans=0;
        vector<vector<int>> vis(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!vis[i][j] && a[i][j]==1){
                    bool val=true;
                    dfs(i,j,a,vis,val);
                    if(val){ans++;}
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends