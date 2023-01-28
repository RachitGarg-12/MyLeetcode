//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int len;
    int f(int i,int left,int price[],vector<vector<int>> &dp){
        if(left==0){return 0;}
        if(i==0){
            return left*price[0];
        }
        if(dp[i][left]!=-1){return dp[i][left];}
        int notcut=f(i-1,left,price,dp);
        int cut=0;
        if(i+1<=left){cut=price[i]+f(i,left-(i+1),price,dp);}
        return dp[i][left]=max(cut,notcut);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends