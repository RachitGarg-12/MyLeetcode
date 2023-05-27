class Solution {
public:
    int n;
    int alice(int i,int turn,vector<int>& stoneValue,vector<vector<int>> &dp){
        if(i>=n){return 0;}
        if(dp[i][turn]!=-1){return dp[i][turn];}
        int ans=(turn==1)?-1e9:1e9;
        int score=0;
        for(int it=i;it<i+3 && it<n ;it++){
            score+=stoneValue[it];
            if(turn){ans=max(ans,score+alice(it+1,0,stoneValue,dp));}
            else{ans=min(ans,alice(it+1,1,stoneValue,dp));}
        }
        return dp[i][turn]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        int tot=0;
        for(auto i:stoneValue){tot+=i;}
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        int a=alice(0,1,stoneValue,dp);
        int b=tot-a;
        if(a>b){return "Alice";}
        else if(a<b){return "Bob";}
        return "Tie";
    }
};