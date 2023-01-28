class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n][amount+1];
        for(int i=0;i<=amount;i++){
            if((i%coins[0])==0){dp[0][i]=i/coins[0];}
            else{dp[0][i]=1e9;}
        }
        for(int i=1;i<n;i++){
           for(int j=0;j<=amount;j++){
               int nottake=dp[i-1][j];
               int take=1e9;
               if(coins[i]<=j){take= 1 + dp[i][j-coins[i]];}
               dp[i][j]=min(nottake,take);               
           }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9){return -1;}
        return ans;
    }
};