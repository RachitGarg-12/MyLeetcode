class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int i=0;i<=amount;i++){
            if((i%coins[0])==0){prev[i]=i/coins[0];}
            else{prev[i]=1e9;}
        }
        for(int i=1;i<n;i++){
           for(int j=0;j<=amount;j++){
               int nottake=prev[j];
               int take=1e9;
               if(coins[i]<=j){take= 1 + cur[j-coins[i]];}
               cur[j]=min(nottake,take);               
           }
            prev=cur;
        }
        int ans=prev[amount];
        if(ans>=1e9){return -1;}
        return ans;
    }
};