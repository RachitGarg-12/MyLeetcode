class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
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
	    for(int i=1;i<n-1;i++){
	        if(dp1[i]>1 && dp2[i]>1){ans=max(ans,dp1[i]+dp2[i]-1);}
	    }
	    
	    return n-ans;        
    }
};