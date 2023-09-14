//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod=1e9+7;
	int ways(int i,int sum,int arr[],int n,vector<vector<int>> &dp){
	    if(i>=n){return (sum==0);}
	    if(dp[i][sum]!=-1){return dp[i][sum]%mod;}
	    int ans=ways(i+1,sum,arr,n,dp)%mod;
	    if(sum-arr[i]>=0){ans=((ans%mod)+ways(i+1,sum-arr[i],arr,n,dp)%mod)%mod;ans%=mod;}
	    return dp[i][sum]=ans%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
           vector<vector<int>> dp(n,vector<int>(sum+1,-1));
           return ways(0,sum,arr,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends