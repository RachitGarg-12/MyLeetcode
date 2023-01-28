//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++){
            int num=i/wt[0];
            dp[0][i]=val[0]*num;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int nottake= dp[i-1][j];
                int take=INT_MIN;
                if(wt[i]<=j){take=val[i]+dp[i][j-wt[i]];}
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[n-1][W];      // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends