class Solution {
public:
    // int f(int i,int amount,vector<int>& coins,vector<vector<int>> &dp){
    //     if(amount==0){return 1;}
    //     if(i==0){
    //         if(amount%coins[0]==0){return 1;}
    //         return 0;
    //     }
    //     if(dp[i][amount]!=-1){return dp[i][amount];}
    //     int nottake=f(i-1,amount,coins,dp);
    //     int take=0;
    //     if(coins[i]<=amount){take=f(i,amount-coins[i],coins,dp);}
    //     return dp[i][amount]=take+nottake;
    // }
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        int dp[n][target+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0){dp[0][i]=1;}
        }
        for(int i=1;i<n;i++){
            for(int amount=0;amount<=target;amount++){
                int nottake=dp[i-1][amount];
                int take=0;
                if(coins[i]<=amount){take=dp[i][amount-coins[i]];}
                dp[i][amount]=take+nottake;                
            }
        }
        return dp[n-1][target];
    }
};