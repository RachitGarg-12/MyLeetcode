class Solution {
public:
    int f(int i,int j,int turn,vector<int>& piles,vector<vector<vector<int>>> &dp){
        if(i>j){return 0;}
        if(dp[i][j][turn]!=-1){return dp[i][j][turn];}
        int ans;
        if(turn){
            ans=max(piles[i]+f(i+1,j,!turn,piles,dp),piles[j]+f(i,j-1,!turn,piles,dp));
        }
        else{
            ans=min(f(i+1,j,!turn,piles,dp),f(i,j-1,!turn,piles,dp));
        }
        return dp[i][j][turn]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int ascore=f(0,n-1,1,piles,dp);
        int tot=0;
        for(auto i:piles){tot+=i;}
        int bscore=tot-ascore;
        return ascore>bscore;
    }
};