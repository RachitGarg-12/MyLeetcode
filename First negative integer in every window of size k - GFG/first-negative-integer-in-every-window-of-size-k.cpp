//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) {
    vector<long long> ans;
    queue<long long> q;
    for(int i=0;i<k-1;i++){
        if(a[i]<0){q.push(i);}
    }
    for(int i=k-1;i<n;i++){
       if(a[i]<0){q.push(i);}
       if(q.empty()){ans.push_back(0);continue;}
       long long j=q.front();
       if(j>=i-k+1 && j<=i){ans.push_back(a[j]);}
       else if(j<i-k+1){
           while(!q.empty() && j<i-k+1){q.pop();j=q.front();}
           if( !q.empty() && j<=i){ans.push_back(a[j]);}
           else{ans.push_back(0);}
       }
       else{ans.push_back(0);}
    }
    return ans;
 }