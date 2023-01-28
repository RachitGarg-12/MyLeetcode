//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int i,int w, int wt[], int val[],vector<vector<int>> &dp){
        if(i==0){
            if(wt[0]<=w){return val[0];}
            return 0;
        }
        if(dp[i][w]!=-1){return dp[i][w];}
        int nottake=f(i-1,w,wt,val,dp);
        int take=INT_MIN;
        if(wt[i]<=w){take=val[i]+f(i-1,w-wt[i],wt,val,dp);}
        return dp[i][w]=max(take,nottake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {    
        vector<int> prev(W+1,0);
        for(int i=wt[0];i<=W;i++){prev[i]=val[0];}
        
        for(int i=1;i<n;i++){
            vector<int> cur(W+1,0);
            for(int j=0;j<=W;j++){
                int nottake= prev[j];
                int take=INT_MIN;
                if(wt[i]<=j){take=val[i]+prev[j-wt[i]];}
                cur[j]=max(take,nottake);
            }
            prev=cur;
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends