//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>a)
	{   int n=a.size();
	    vector<int> dp1(n,1),dp2(n,1);
	    int ans=1;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[i]>a[j] && dp1[j]+1>dp1[i]){
	                dp1[i]=dp1[j]+1;
	            }
	        }
	    }
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(a[i]>a[j] && dp2[j]+1>dp2[i]){
	                dp2[i]=dp2[j]+1;
	            }
	        }
	    }	    
	    for(int i=0;i<n;i++){
	        ans=max(ans,dp1[i]+dp2[i]-1);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends