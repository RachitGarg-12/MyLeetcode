//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool helper(int pos, int arr[], int sum, int n, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (pos == n || sum < 0) return false;

        if (dp[pos][sum] != -1) {
            return dp[pos][sum];
        }

        return dp[pos][sum] = helper(pos + 1, arr, sum - arr[pos], n, dp) || helper(pos + 1, arr, sum, n, dp);
    }

public:
    bool equalPartition(int N, int arr[]) {
        int sum = accumulate(arr, arr + N, 0);

        if (sum % 2 != 0) return false;

        sum /= 2;

        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));

        return helper(0, arr, sum, N, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends