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


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
    vector<long long> neg;
    for(int i=0;i<n;i++){
        if(a[i]<0){neg.push_back(i);}
    }
    long long j=0;
    int len=neg.size();
    vector<long long> ans;
    for(int i=k-1;i<n;i++){
        if(j<len && neg[j]<=i && neg[j]>=i-k+1){ans.push_back(a[neg[j]]);}
        else if(j<len && neg[j]<i-k+1){
            while(neg[j]<i-k+1 && j<len){j++;}
            if(j<len && neg[j]<=i){ans.push_back(a[neg[j]]);}
            else{ans.push_back(0);}
        }
        else{ans.push_back(0);}
    }
    return ans;
 }