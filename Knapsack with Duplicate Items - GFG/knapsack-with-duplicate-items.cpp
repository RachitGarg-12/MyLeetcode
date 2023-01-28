//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int w, int wt[], int val[],vector<vector<int>> &dp){
        if(i<0){return 0;}
        if(dp[i][w]!=-1){return dp[i][w];}
        int nottake=f(i-1,w,wt,val,dp);
        int take=INT_MIN;
        if(wt[i]<=w){take=val[i]+f(i,w-wt[i],wt,val,dp);}
        return dp[i][w]=max(take,nottake);
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return f(n-1,W,wt,val,dp);       // code here
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