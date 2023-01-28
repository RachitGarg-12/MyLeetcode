//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int i,int len,int price[],vector<vector<int>> &dp){
        if(len==0){return 0;}
        if(i==0){
            return len*price[0];
        }
        if(dp[i][len]!=-1){return dp[i][len];}
        int notcut=f(i-1,len,price,dp);
        int cut=0;
        if(i+1<=len){cut=price[i]+f(i,len-(i+1),price,dp);}
        return dp[i][len]=max(cut,notcut);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){dp[0][i]=i*price[0];}
        
        for(int i=1;i<n;i++){
            for(int len=0;len<=n;len++){
                 int notcut=dp[i-1][len];
                 int cut=0;
                 if(i+1<=len){cut=price[i]+dp[i][len-(i+1)];}
                 dp[i][len]=max(cut,notcut);                
            }
        }
        return dp[n-1][n];
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