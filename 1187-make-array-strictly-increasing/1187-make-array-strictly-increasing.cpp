class Solution {
public:
    int n,m;
    int f(int i,int last,vector<int>& arr1, vector<int>& arr2,vector<map<int,int>> &dp){
        if(i==n){return 0;}
        if(dp[i].find(last)!=dp[i].end()){return dp[i][last];}
        int ans=1e9;
        if(arr1[i]>last){ans=f(i+1,arr1[i],arr1,arr2,dp);}
        int ind=upper_bound(arr2.begin(),arr2.end(),last)-arr2.begin();
        if(ind<m){ans=min(ans,1+f(i+1,arr2[ind],arr1,arr2,dp));}
        return dp[i][last]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n=arr1.size(),m=arr2.size();
        sort(arr2.begin(),arr2.end());
        vector<map<int,int>> dp(n);
        int ans=f(0,-1,arr1,arr2,dp);
        if(ans==1e9){return -1;}
        return ans;
    }
};