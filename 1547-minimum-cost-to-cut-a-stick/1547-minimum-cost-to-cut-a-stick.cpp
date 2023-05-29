class Solution {
public:
    int rec(int l,int r,vector<int>&a,vector<vector<int>> &dp){
        if(r-l<=1){return 0;}
        if(dp[l][r]!=-1){return dp[l][r];}
        int ans=1e9;
        for(int i=l+1;i<r;i++){
            ans=min(ans,(a[r]-a[l])+rec(l,i,a,dp)+rec(i,r,a,dp));
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int len=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(len+2,vector<int>(len+2,-1));
        vector<int> a(len+2);
        a[0]=0;
        for(int i=1;i<=len;i++){
            a[i]=cuts[i-1];
        }
        a[len+1]=n;
        return rec(0,len+1,a,dp);
    }
};