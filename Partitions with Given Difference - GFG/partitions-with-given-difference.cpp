//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod=1e9+7;
    int f(int i,vector<int>& arr,int sum,vector<vector<int>> &dp){
        if(i==0){
            if(sum==0 && arr[0]==0){return 2;}
            if(sum==0 || sum==arr[0]){return 1;}
            return 0;
        }
        if(dp[i][sum]!=-1){return dp[i][sum];}
        int nottake=f(i-1,arr,sum,dp)%mod;
        int take=0;
        if(arr[i]<=sum){take=f(i-1,arr,sum-arr[i],dp)%mod;}
        return dp[i][sum]=(take%mod+nottake%mod)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int tot=0;
        for(auto i:arr){tot+=i;}
        if( tot-d<0 || (tot-d)%2){return 0;}
        int s2=(tot-d)/2;
        vector<vector<int>> dp(n+1,vector<int>(s2+1,-1));
        return f(n-1,arr,s2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends