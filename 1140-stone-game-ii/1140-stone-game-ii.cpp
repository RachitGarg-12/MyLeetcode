class Solution {
public:
    int n;
    int f(int i,int m,int turn,vector<int>&piles,vector<vector<vector<int>>>&dp){
        if(i>=n){return 0;}
        if(dp[i][m][turn]!=-1){return dp[i][m][turn];}
        int ans=(turn==1)?0:1e9;
        int cur=0;
        for(int it=0;i+it<n && it<2*m;it++){
            cur+=piles[i+it];
            if(turn==1){
                ans=max(ans,cur+f(i+it+1,max(m,it+1),0,piles,dp));
            }
            else{
                ans=min(ans,f(i+it+1,max(m,it+1),1,piles,dp));
            }
        }
        return dp[i][m][turn]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return f(0,1,1,piles,dp);
    }
};