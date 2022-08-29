class Solution {
public:
    vector<vector<int>> dp;vector<int> a;
    int rec(int l,int r){
    //returns the min cost for vutting in l to r;
    //pruning
    //base case
    if(r-l<=1){return 0;}
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=1e9;
    for(int i=l+1;i<r;i++){
        ans=min(ans,(a[r]-a[l])+rec(l,i)+rec(i,r));
    }
   return dp[l][r]=ans;
}
    int minCost(int n, vector<int>& cuts) {
    int l=cuts.size();
    sort(cuts.begin(),cuts.end());
    dp.resize(l+2,vector<int>(l+2,-1));a.resize(l+2);a[0]=0;
    for(int i=1;i<=l;i++){a[i]=cuts[i-1];}
        a[l+1]=n;
        return rec(0,l+1);
    }
};